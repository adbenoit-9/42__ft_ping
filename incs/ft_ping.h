/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:40 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/13 17:07:33 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "defs.h"
# include "error.h"

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
	long long int		nsent;
	double				max_time;
	double				min_time;
	double				total_time;
	int					status;
}	t_stats;


typedef struct s_ping_data
{
	char				*host;
	char				ip[INET_ADDRSTRLEN];
	struct sockaddr		sockaddr;
	int					flag;
	long long int		count;
	int					sockfd;
	uint8_t				pid;
	t_packet			request_packet;
	t_packet			reply_packet;
	t_stats				stats;
}				t_ping_data;

extern t_ping_data	g_data;

int				fatal_error(int error, char *arg, char option);
int				ft_perror(char *error, char *fct);
char			*ft_strerror(int error);
void			handle_signal(int signum);
bool			parser(char **arg);
int				print_help(void);
void			clean(void);
int				ft_isnumber(char *str);
t_packet		request_packet(void);
unsigned short	checksum(unsigned short *addr, size_t len);
void			ping(void);
void			stats_report(void);
bool			recv_echo_reply(struct timeval req_time);
void			init_socket(void);
void			ft_wait(struct timeval start_time, size_t nb_sec);

void			print_addrinfo(struct addrinfo info);
void			print_icmp(struct icmp icmphdr);
void			print_ip(struct ip iphdr);
void			print_msg(struct msghdr msg);
void			print_time(struct timeval time);

#endif
