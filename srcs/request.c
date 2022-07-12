/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:52:44 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/12 19:24:18 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/* https://www.rfc-editor.org/rfc/rfc792 */

/* https://book.huihoo.com/iptables-tutorial/x1078.htm */

t_packet	request_packet(void)
{
	t_packet	packet;

	bzero(&packet, sizeof(t_packet));
	packet.echo.request.header.icmp_type = ICMP_ECHO;
	packet.echo.request.header.icmp_code = 0;
	packet.echo.request.header.icmp_id = g_data.pid;
	packet.echo.request.header.icmp_seq = 1;
	return (packet);
}

void	ping(void)
{
	ssize_t	len;

	send_packet.header.icmp_cksum = 0;
	send_packet.header.icmp_cksum = checksum(
		(unsigned short *)&send_packet.header, sizeof(send_packet));
	len = sendto(g_data.sockfd, &g_data.request_packet, sizeof(send_packet), 0,
			&g_data.sockaddr, sizeof(g_data.sockaddr));
#ifdef DEBUG
	if (len == -1)
		printf("%s[Transmission failed]%s %s\n", S_RED, S_NONE, strerror(errno));
	else
		printf("%s[Packet sent]%s %zd bytes\n", S_GREEN, S_NONE, len);
	print_icmp(send_packet.header);
#endif
	if (len == -1) {
		if (errno == ENOTCONN)
			printf("ft_ping: sendto: Socket is not connected\n");
		else if (errno == EWOULDBLOCK)
			printf("Request timeout for icmp_seq %hu\n", send_packet.header.icmp_seq);
	}
	else {
		++g_data.state.nsent;
	}
	if ((g_data.flag & COUNT) == COUNT && send_packet.header.icmp_seq == g_data.count)
        return (ping_report());
	++send_packet.header.icmp_seq;
	alarm(TIME_INTERVAL);
}
