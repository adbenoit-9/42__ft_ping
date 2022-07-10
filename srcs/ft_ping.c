/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:20:21 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/10 17:29:18 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int	ft_ping(void)
{
	int				fd;
	size_t			icmp_seq;
	ssize_t			ret;
	struct msghdr	mess;

	g_data.packet = icmp_echo_packet();
	printf("%ld\n", sizeof(g_data.packet));
	fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (fd == -1)
		ft_perror(ERR_SOCK, NULL, 0);
	printf("PING %s (%s) %d(%d) bytes of data.\n", g_data.host, g_data.ip,
		DATA_SIZE, DATA_SIZE + HEADER_SIZE);
	icmp_seq = 1;
	while (true)
	{
		sendto(fd, &g_data.packet, PACKET_SIZE, 0,
			g_data.sockaddr, sizeof(g_data.sockaddr));
		perror("");
		ret = recvmsg(fd, &mess, 0);
		printf("%ld\n", ret);
		perror("");
		++icmp_seq;
		exit(1);
	}
	return (0);
}
