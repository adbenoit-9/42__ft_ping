/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 02:43:41 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/12 16:31:34 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	init_socket(void)
{
	g_data.sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (g_data.sockfd == -1)
		ft_perror(SOCKERR, NULL, 0);
	if (setsockopt(g_data.sockfd, IPPROTO_IP, IP_TTL, &g_data.ttl, sizeof(g_data.ttl)) == -1)
        ft_perror(SOCKERR, NULL, 0);
}
