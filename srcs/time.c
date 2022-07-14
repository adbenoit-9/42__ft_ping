/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:21:42 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/14 17:51:21 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

double	timeval_to_ms(struct timeval t)
{
	return (t.tv_sec * 1000. + t.tv_usec / 1000.);
}

void	set_time_stats(double time_ms)
{
	if (g_data.stats.nsent == 1)
	{
		g_data.stats.min_time = time_ms;
		g_data.stats.max_time = time_ms;
	}
	g_data.stats.min_time = time_ms < g_data.stats.min_time ? time_ms : g_data.stats.min_time;
	g_data.stats.max_time = time_ms > g_data.stats.max_time ? time_ms : g_data.stats.max_time;
	g_data.stats.sum_time += time_ms;
	g_data.stats.sum_square_time += time_ms * time_ms;
}
