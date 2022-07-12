/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:45:31 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/12 18:50:10 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H

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
# define LLONG_MAX 9223372036854775807
# define send_packet g_data.request_packet.echo.request
# define recv_packet g_data.reply_packet.echo.reply

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
# define TOTAL_SIZE PACKET_SIZE + HEADER_SIZE
# define DEFAULT_TTL 64
# define VERSION 4

/*
** -- Exit codes --
*/
# define SUCCESS 0
# define USAGE_ERR 1
# define ERROR 2

/*
** -- Error codes --
*/
# define NOMEM 0
# define SOCKERR 1
# define TRANSMERR 2
# define NOHOST 3
# define BADHOST 4
# define BADAF 5
# define BADARG 6
# define BADOPT 7
# define ARGOOR 8

/*
** -- Error messages --
*/
# define NOMEM_MSG "ft_ping: out of memory\n"
# define SOCKERR_MSG "ft_ping: socket error\n"
# define TRANSMERR_MSG "ft_ping: transmission failed\n"
# define NOHOST_MSG "ft_ping: usage error: Destination address required\n"
# define BADHOST_MSG "ft_ping: %s: Name or service not known\n"
# define BADAF_MSG "ft_ping: %s: Address family for hostname not supported\n"
# define BADARG_MSG  "ft_ping: invalid agument: '%s'\n"
# define BADOPT_MSG "ft_ping: invalid option -- %c\n"
# define ARGOOR_MSG  "ft_ping: invalid agument: '%s': out of range: %d <= value <= %ld\n"

#endif
