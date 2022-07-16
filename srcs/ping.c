/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:31:16 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/16 16:17:10 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	ping(void)
{
	struct timeval	req_time;
	int				ret;

	printf("PING %s (%s) %d(%d) bytes of data.\n", g_data.host, g_data.ip,
		PACKET_SIZE, PACKET_SIZE + HEADER_SIZE);
	g_data.request_packet = request_packet();
	while (true)
	{
		g_data.status = PENDING;
		if (FLAG_ISSET(F_COUNT) && g_data.count == g_data.stats.nrecv)
			ping_statistics();
		if (gettimeofday(&req_time, NULL) == -1)
			fatal_error(errno, "gettimeofday", 0);
		if (!FLAG_ISSET(F_COUNT) || g_data.stats.nsent < g_data.count)
			send_echo_request();
		alarm(TIMEOUT);
		ret = recv_echo_reply(req_time);
		if (ret == ETIMEDOUT && FLAG_ISSET(F_VERBOSE) && !FLAG_ISSET(F_QUIET))
			printf("Request timeout for icmp_seq %lld\n", g_data.stats.nsent);
		else if (ret == EP_REPLY && !FLAG_ISSET(F_QUIET))
			print_packet(g_data.reply_packet, g_data.stats.nsent);
		ft_wait(req_time, TIME_INTERVAL);
	}
}
