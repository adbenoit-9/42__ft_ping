/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:52:44 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/18 14:03:05 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_packet	request_packet(void)
{
	t_packet	packet;

	bzero(&packet, sizeof(t_packet));
	packet.echo.request.header.icmp_type = ICMP_ECHO;
	packet.echo.request.header.icmp_code = 0;
	packet.echo.request.header.icmp_id = g_data.pid;
	packet.echo.request.header.icmp_seq = 0;
	return (packet);
}

void	send_echo_request(struct timeval *timeval)
{
	ssize_t	len;

	++S_PACKET.header.icmp_seq;
	S_PACKET.header.icmp_cksum = 0;
	S_PACKET.header.icmp_cksum = checksum(
			(unsigned short *)&S_PACKET.header, sizeof(S_PACKET));
	if (gettimeofday(timeval, NULL) == -1)
		fatal_error(errno, "gettimeofday", 0);
	len = sendto(g_data.sockfd, &g_data.request_packet, sizeof(S_PACKET), 0,
			&g_data.sockaddr, sizeof(g_data.sockaddr));
# ifdef DEBUG
	if (len == -1)
		printf("%s[Transmission failed]%s %s\n", S_RED, S_NONE, strerror(errno));
	else
		printf("%s[Packet sent]%s %zd bytes\n", S_GREEN, S_NONE, len);
	debug_icmp(S_PACKET.header);
# endif
	if (len == -1 && FLAG_ISSET(F_VERBOSE))
		ft_perror(ft_strerror(errno), "sendto");
	++g_data.stats.nsent;
}
