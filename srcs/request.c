/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:52:44 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/11 02:38:49 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/* https://www.rfc-editor.org/rfc/rfc792 */

/* https://book.huihoo.com/iptables-tutorial/x1078.htm */

t_icmp_packet	request_packet(void)
{
	t_icmp_packet	packet;

	memset(&packet.echo.request.header, 0, sizeof(struct icmp));
	packet.echo.request.header.icmp_type = ECHO_REQUEST_TYPE;
	packet.echo.request.header.icmp_code = ECHO_REQUEST_CODE;
	packet.echo.request.header.icmp_id = getpid();
	packet.echo.request.header.icmp_seq = 1;
	return (packet);
}

void	ping(void)
{
	g_data.send_packet.header.icmp_cksum = 0;
	g_data.send_packet.header.icmp_cksum = checksum(
		(unsigned short *)&g_data.send_packet.header, sizeof(struct icmp));
	if (DEBUG)
		print_icmp(g_data.send_packet.header);
	sendto(g_data.sockfd, &g_data.icmp_packet, TOTAL_SIZE, 0,
			g_data.sockaddr, sizeof(g_data.sockaddr));
    if ((g_data.flag & COUNT) == COUNT && g_data.send_packet.header.icmp_seq == g_data.count)
        return (ping_report());
	++g_data.send_packet.header.icmp_seq;
	alarm(TIME_INTERVAL);
}
