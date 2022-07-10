/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:40 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/10 19:57:43 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "defs.h"

typedef struct s_echo_packet
{
	// struct iphdr	ip;
	struct icmp	icmp;
	char		data[DATA_SIZE];
}				t_echo_packet;

typedef struct s_data
{
	char				*host;
	char				*ip;
	int					flag;
	long long int		count;
	t_echo_packet		packet;
	struct sockaddr		*sockaddr;
}				t_data;

extern t_data	g_data;

int				ft_perror(int error, char *host, char option);
void			handle_signal(int signum);
int				ft_ping(void);
int				parser(char **arg);
int				print_help(void);
void			print_addrinfo(struct addrinfo info);
void			clean(void);
void			stop_ping(void);
int				ft_isnumber(char *str);
t_echo_packet	icmp_echo_packet(void);
unsigned short	checksum(unsigned short *addr, size_t len);

#endif
