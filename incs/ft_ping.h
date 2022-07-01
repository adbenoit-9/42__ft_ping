/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:40 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/01 18:12:59 by adbenoit         ###   ########.fr       */
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

# define NB_FLAGS 3
# define FLAGS "46h"

# define ERR_OPTION 1
# define ERR_USAGE 2
# define ERR_AF 3

typedef struct s_data
{
    char    *host;
    char    flags[NB_FLAGS + 1];
    int     af;
    struct addrinfo *addrinfo;
}               t_data;

extern t_data  g_data;

int     ft_strerror(int error, char *host, char option);
void    handle_signal(int signum);
int     ft_ping(char *host);
int     parser(char **arg);
void    print_help(void);

#endif
