/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 02:43:41 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/14 18:34:34 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	init_socket(void)
{
	int				ttl;
	struct timeval	timeout;

	timeout.tv_sec = TIMEOUT;
	timeout.tv_usec = 0;
	g_data.sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (g_data.sockfd == -1)
		fatal_error(errno, "socket", 0);
	ttl = DEFAULT_TTL;
	if (setsockopt(g_data.sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) == -1)
		fatal_error(errno, "setsockopt", 0);
	// if (setsockopt (g_data.sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout,
	// 		sizeof(timeout)) == -1)
	// 	fatal_error(errno, "setsockopt", 0);
}
