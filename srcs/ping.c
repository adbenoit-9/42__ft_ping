/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:31:16 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/16 13:12:18 by adbenoit         ###   ########.fr       */
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
		if ((g_data.flag & COUNT) && g_data.count == g_data.stats.nrecv)
			ping_statistics();
		if (gettimeofday(&req_time, NULL) == -1)
			fatal_error(errno, "gettimeofday", 0);
		if (!(g_data.flag & COUNT) || g_data.stats.nsent < g_data.count)
			send_echo_request();
		alarm(TIMEOUT);
		ret = recv_echo_reply(req_time);
		if (ret != SUCCESS && (g_data.flag & VERBOSE) && !(g_data.flag & QUIET)) {
			printf("Request timeout for icmp_seq %lld\n",
				g_data.stats.nsent - 1);
		}
		if (ret == EP_REPLY && g_data.flag & VERBOSE && !(g_data.flag & QUIET))
			print_packet(g_data.reply_packet);
		ft_wait(req_time, TIME_INTERVAL);
	}
}
