/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:21:42 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/15 14:34:59 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

double	tv_to_ms(struct timeval t)
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
	g_data.stats.min_time = time_ms < g_data.stats.min_time ?
		time_ms : g_data.stats.min_time;
	g_data.stats.max_time = time_ms > g_data.stats.max_time ?
		time_ms : g_data.stats.max_time;
	g_data.stats.sum_time += time_ms;
	g_data.stats.sum_square_time += (time_ms * time_ms);
}

void	ft_wait(struct timeval start_time, size_t nb_sec)
{
	struct timeval	current_time;
	double			end_ms;
	double			current_ms;

	start_time.tv_sec = start_time.tv_sec + nb_sec;
	end_ms = tv_to_ms(start_time);
	if (gettimeofday(&current_time, NULL) == -1)
		fatal_error(errno, "gettimeofday", 0);
	current_ms = tv_to_ms(current_time);
	while (current_ms < end_ms)
	{
		if (gettimeofday(&current_time, NULL) == -1)
			fatal_error(errno, "gettimeofday", 0);
		current_ms = tv_to_ms(current_time);
	}
}
