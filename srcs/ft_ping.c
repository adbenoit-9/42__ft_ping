/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:20:21 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/10 20:07:20 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int	ft_ping(void)
{
	int				sockfd;
	ssize_t			ret;
	struct msghdr	mess;
	int				ttl;

	g_data.packet = icmp_echo_packet();
	printf("%ld\n", sizeof(g_data.packet));
	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd == -1)
		ft_perror(ERR_SOCK, NULL, 0);
	printf("PING %s (%s) %d(%d) bytes of data.\n", g_data.host, g_data.ip,
		DATA_SIZE, DATA_SIZE + HEADER_SIZE);
	ttl = DEFAULT_TTL;
	setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));
	while (true)
	{
		sendto(sockfd, &g_data.packet, PACKET_SIZE, 0,
			g_data.sockaddr, sizeof(g_data.sockaddr));
		// perror("");
		ret = recvmsg(sockfd, &mess, 0);
		printf("%ld\n", ret);
		perror("");
		++g_data.packet.icmp.icmp_seq;
		exit(1);
	}
	return (0);
}
