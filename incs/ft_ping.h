/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:40 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/11 23:43:55 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "defs.h"

typedef struct s_icmp_packet
{
	union {
		struct request
		{
			struct icmp	header;
			char		data[PACKET_SIZE];
		}	request;
		struct reply
		{
			struct ip		iphdr;
			struct icmp		header;
			char			data[PACKET_SIZE];
		}	reply;
		
	}	echo;
} t_icmp_packet;

typedef struct s_ping_data
{
	char				*host;
	char				*ip;
	int					flag;
	int					sockfd;
	int					status;
	long long int		count;
	t_icmp_packet		request_packet;
	t_icmp_packet		reply_packet;
	char				recv_buf[TOTAL_SIZE];
	struct sockaddr		*sockaddr;
}				t_ping_data;

extern t_ping_data	g_data;

int				ft_perror(int error, char *arg, char option);
void			handle_signal(int signum);
bool			parser(char **arg);
int				print_help(void);
void			print_addrinfo(struct addrinfo info);
void			clean(void);
int				ft_isnumber(char *str);
t_icmp_packet	request_packet(void);
unsigned short	checksum(unsigned short *addr, size_t len);
void			print_icmp(struct icmp icmphdr);
void			ping(void);
void			ping_report(void);
void    		recv_echo_reply(void);
void			init_socket(void);

#endif
