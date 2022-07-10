/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:45:31 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/10 19:45:20 by adbenoit         ###   ########.fr       */
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
# include <netinet/ip.h>
// # include <linux/icmp.h>
# include <netinet/ip_icmp.h>
# include <stdbool.h>

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
** -- Packet info --
*/
# define DATA_SIZE 56
# define HEADER_SIZE 28
# define PACKET_SIZE DATA_SIZE + HEADER_SIZE
# define ECHO_REQUEST_TYPE 8
# define ECHO_REQUEST_CODE 0
# define DEFAULT_TTL 64
# define VERSION 4

/*
** -- Errors --
*/
# define ERR_OPTION 1
# define ERR_USAGE 2
# define ERR_AF 3
# define ERR_SOCK 4
# define ERR_ARG 5

#endif
