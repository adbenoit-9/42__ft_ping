/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:40 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/16 18:08:41 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "defs.h"

typedef struct s_packet
{
	union u_echo {
		struct s_request
		{
			struct icmp		header;
			char			data[PACKET_SIZE - 20];
		}	request;
		struct s_reply
		{
			struct ip		iphdr;
			struct icmp		icmphdr;
			char			data[PACKET_SIZE - 40];
		}	reply;
	}	echo;
}	t_packet;

typedef struct s_stats
{
	long long int		nrecv;
	long long int		nerror;
	long long int		nsent;
	double				max_time;
	double				min_time;
	double				sum_time;
	double				sum_square_time;
	struct timeval		begin_time;
}	t_stats;

typedef	struct s_flag
{
	int					isset;
	long long int		count;
	int					ttl;
}				t_flag;

typedef struct s_ping_data
{
	short				status;
	char				*host;
	char				ip[INET_ADDRSTRLEN];
	struct sockaddr		sockaddr;
	t_flag				flag;
	int					sockfd;
	uint8_t				pid;
	t_packet			request_packet;
	t_packet			reply_packet;
	t_stats				stats;
}				t_ping_data;

extern t_ping_data	g_data;

void			clean(void);
bool			parser(char **arg);
void			ping(void);
void			handle_signal(int signum);
int				print_usage(void);
int				print_packet(t_packet packet, long long int n);
t_packet		request_packet(void);
void			send_echo_request(void);
int				recv_echo_reply(struct timeval req_time);
void			print_statistics(void);

/* Algorithms */
unsigned short	checksum(unsigned short *addr, size_t len);
double			standard_deviation(double sum_xi, double sum_square_xi, int n);

/* Time handler functions */
void			ft_wait(struct timeval start_time, size_t nb_sec);
double			tv_to_ms(struct timeval t);
void			set_time_stats(double time_ms);

/* Error functions */
char			*ft_strerror(int error);
int				ft_perror(const char *error, const char *fct);
int				fatal_error(int error, const char *arg, const char option);

/*  libft functions */
int				ft_isnumber(const char *str);
char			*ft_strdup(const char *s1);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);

/* Debug utils functions */
void			print_addrinfo(struct addrinfo info);
void			print_icmp(struct icmp icmphdr);
void			print_ip(struct ip iphdr);
void			print_msg(struct msghdr msg);
void			print_time(struct timeval time);

#endif
