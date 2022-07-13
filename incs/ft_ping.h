/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:40 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/13 11:41:19 by adbenoit         ###   ########.fr       */
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
			struct icmp	header;
			char		data[PACKET_SIZE - 20];
		}	request;
		struct s_reply
		{
			struct ip		iphdr;
			struct icmp		icmphdr;
			char			data[PACKET_SIZE - 20];
		}	reply;
	}	echo;
}	t_packet;

typedef struct s_state
{
	size_t				nrecv;
	size_t				nsent;
	int					status;	
}	t_state;

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
	t_state				state;
}				t_ping_data;

extern t_ping_data	g_data;

int				ft_perror(int error, char *arg, char option);
void			handle_signal(int signum);
bool			parser(char **arg);
int				print_help(void);
void			print_addrinfo(struct addrinfo info);
void			clean(void);
int				ft_isnumber(char *str);
t_packet		request_packet(void);
unsigned short	checksum(unsigned short *addr, size_t len);
void			print_icmp(struct icmp icmphdr);
void			ping(void);
void			ping_report(void);
void			recv_echo_reply(void);
void			init_socket(void);
void			print_msg(struct msghdr msg);

#endif
