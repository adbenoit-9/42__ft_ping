/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:45:31 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/13 14:56:20 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

/*
** -- Includes --
*/
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
# include <netinet/ip_icmp.h>
# include <stdbool.h>

# define TIME_INTERVAL 1
# define TIMEOUT 2
# define LLONG_MAX 9223372036854775807
# define S_PACKET g_data.request_packet.echo.request
# define R_PACKET g_data.reply_packet.echo.reply

/*
** -- Color codes --
*/
# define S_NONE    "\033[0m"
# define S_RED     "\033[1;31m"
# define S_GREEN   "\033[1;32m"
# define S_YELLOW  "\033[1;33m"
# define S_BLUE    "\033[1;34m"
# define S_PURPLE  "\033[1;35m"
# define S_CYAN    "\033[1;36m"

/*
** -- Flags --
*/
# define NB_FLAGS 4
# define FLAGS "hvcq"
# define HELP 0x80
# define VERBOSE 0x40
# define COUNT 0x20
# define QUIET 0x10

/*
** -- Transmission status --
*/
# define WAIT 0
# define PACKET_SENT 1
# define STOP 2

/*
** -- Packet info --
*/
# define HEADER_SIZE 28
# define PACKET_SIZE 56
# define DEFAULT_TTL 64
# define VERSION 4

/*
** -- Exit codes --
*/
# define SUCCESS 0
# define USAGE_ERR 1
# define ERROR 2

#endif
