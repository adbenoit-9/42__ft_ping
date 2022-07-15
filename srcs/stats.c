/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:20:21 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/15 14:31:30 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

#ifndef OS

void	ping_statistics(void)
{
	struct timeval	end_time;
	double			sum_time;
	double			loss_ratio;
	double			avg;

	if (gettimeofday(&end_time, NULL) == -1)
		fatal_error(errno, "gettimeofday", 0);
	sum_time = tv_to_ms(end_time) - tv_to_ms(g_data.stats.begin_time);
	printf("\n--- %s ping statistics ---\n", g_data.host);
	loss_ratio = 0;
	if (g_data.stats.nsent)
		loss_ratio = (double)(g_data.stats.nsent - g_data.stats.nrecv) / g_data.stats.nsent;
	printf("%lld packets transmitted, %lld packets received, %ld%c packet loss, time %dms\n",
		g_data.stats.nsent, g_data.stats.nrecv, (size_t)(loss_ratio * 100), '%', (int)sum_time);
	if (g_data.stats.nrecv)
	{
		avg = g_data.stats.sum_time / g_data.stats.nrecv;
		printf("rtt min/avg/max/mdev = %.3f/%.3f/%.3f/%.3f ms\n",
			g_data.stats.min_time, avg, g_data.stats.max_time,
			standard_deviation(g_data.stats.sum_time, g_data.stats.sum_square_time,
				g_data.stats.nrecv));
	}
	clean();
	exit(SUCCESS);
}

#else

void	ping_statistics(void)
{
	struct timeval	end_time;
	double			sum_time;
	double			loss_ratio;
	double			avg;

	if (gettimeofday(&end_time, NULL) == -1)
		fatal_error(errno, "gettimeofday", 0);
	sum_time = tv_to_ms(end_time) - tv_to_ms(g_data.stats.begin_time);
	printf("\n--- %s ping statistics ---\n", g_data.host);
	loss_ratio = 0;
	if (g_data.stats.nsent)
		loss_ratio = (double)(g_data.stats.nsent - g_data.stats.nrecv) / g_data.stats.nsent;
	printf("%lld packets transmitted, %lld packets received, %.1f%c packet loss\n",
		g_data.stats.nsent, g_data.stats.nrecv, loss_ratio * 100, '%');
	if (g_data.stats.nrecv)
	{
		avg = g_data.stats.sum_time / g_data.stats.nrecv;
		printf("round-trip min/avg/max/stddev = %.3f/%.3f/%.3f/%.3f ms\n",
			g_data.stats.min_time, avg, g_data.stats.max_time,
			standard_deviation(g_data.stats.sum_time, g_data.stats.sum_square_time,
				g_data.stats.nrecv));
	}
	clean();
	exit(SUCCESS);
}

#endif
