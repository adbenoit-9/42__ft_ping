/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:40 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/10 17:26:45 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sysexits.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <signal.h>
# include <arpa/inet.h>
# include <ctype.h>
# include <netinet/ip.h>
# include <linux/icmp.h>

# define NB_FLAGS 4
# define FLAGS "hvcq"
# define HELP 0x80
# define VERBOSE 0x40
# define COUNT 0x20
# define QUIET 0x10

# define DATA_SIZE 56
# define HEADER_SIZE 28
# define PACKET_SIZE DATA_SIZE + HEADER_SIZE
# define ECHO_REQUEST_TYPE 8
# define ECHO_REQUEST_CODE 0
# define DEFAULT_TTL 64
# define VERSION 4

# define ERR_OPTION 1
# define ERR_USAGE 2
# define ERR_AF 3
# define ERR_SOCK 4
# define ERR_ARG 5

typedef struct s_echo_packet
{
	struct iphdr	ip;
	struct icmphdr	icmp;
	char			data[DATA_SIZE];
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

#endif
