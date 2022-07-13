/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 02:43:41 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/13 11:53:39 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	init_socket(void)
{
	int				ttl;
	struct timeval	timeout;

	timeout.tv_sec = 2;
	timeout.tv_usec = 0;
	g_data.sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (g_data.sockfd == -1)
		ft_perror(SOCKERR, NULL, 0);
	ttl = DEFAULT_TTL;
	if (setsockopt(g_data.sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) == -1)
		ft_perror(SOCKERR, NULL, 0);
	if (setsockopt (g_data.sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout,
			sizeof(timeout)) == -1)
		ft_perror(SOCKERR, NULL, 0);
}
