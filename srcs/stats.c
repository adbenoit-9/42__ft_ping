/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:20:21 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/13 18:25:15 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	stats_report(void)
{
	double	loss;
	
	g_data.stats.status = STOP;
	printf("\n--- %s ping statistics ---\n", g_data.host);
	loss = g_data.stats.nsent - g_data.stats.nrecv;
	printf("%lld packets transmitted, %lld packets received, %.1f%c packet loss\n",
		g_data.stats.nsent, g_data.stats.nrecv,
		(loss / g_data.stats.nsent) * 100., '%');
	if (g_data.stats.nrecv)
	{
		printf("rtt min/avg/max/mdev = %.3f/%.3f/%.3f ms\n",
			g_data.stats.min_time, g_data.stats.total_time / g_data.stats.nrecv,
			g_data.stats.max_time);
	}
	clean();
	exit(SUCCESS);
}
