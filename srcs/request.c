/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:52:44 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/11 23:41:11 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/* https://www.rfc-editor.org/rfc/rfc792 */

/* https://book.huihoo.com/iptables-tutorial/x1078.htm */

t_icmp_packet	request_packet(void)
{
	t_icmp_packet	packet;

	memset(&packet.echo.request.header, 0, sizeof(struct icmp));
	packet.echo.request.header.icmp_type = ICMP_ECHO;
	packet.echo.request.header.icmp_code = 0;
	packet.echo.request.header.icmp_id = getpid();
	packet.echo.request.header.icmp_seq = 1;
	return (packet);
}

void	ping(void)
{
	ssize_t	len;

	send_packet.header.icmp_cksum = 0;
	send_packet.header.icmp_cksum = checksum(
		(unsigned short *)&send_packet.header, sizeof(struct icmp));
	len = sendto(g_data.sockfd, &g_data.request_packet, TOTAL_SIZE, 0,
			g_data.sockaddr, sizeof(g_data.sockaddr));
#ifdef DEBUG
	if (len == -1)
		printf("%s[Transmission failed]%s %s\n", S_RED, S_NONE, strerror(errno));
	else
		printf("%s[Packet sent]%s %zd bytes\n", S_GREEN, S_NONE, len);
	print_icmp(send_packet.header);
#endif
	if (len == -1)
		ft_perror(TRANSMERR, NULL, 0);
	g_data.status = PACKET_SENT;
    if ((g_data.flag & COUNT) == COUNT && send_packet.header.icmp_seq == g_data.count)
        return (ping_report());
	++send_packet.header.icmp_seq;
	alarm(TIME_INTERVAL);
}
