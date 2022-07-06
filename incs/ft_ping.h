/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:40 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/06 12:02:11 by adbenoit         ###   ########.fr       */
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

# define NB_FLAGS 4
# define FLAGS "46hv"

# define ERR_OPTION 1
# define ERR_USAGE 2
# define ERR_AF 3

typedef struct	s_data
{
	char			*host;
	char			*ip;
	char			flags[NB_FLAGS + 1];
	int				af;
	struct addrinfo	*addrinfo;
}				t_data;

extern t_data	g_data;

int		ft_strerror(int error, char *host, char option);
void	handle_signal(int signum);
int		ft_ping(void);
int		parser(char **arg);
int		print_help(void);
void	print_addrinfo(struct addrinfo info);
void	clean(void);

#endif
