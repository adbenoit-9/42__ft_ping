/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:21:49 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/04 15:27:06 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static void	stop_ping(void)
{
	printf("\n--- localhost ping statistics ---\n");
	free(g_data.host);
	freeaddrinfo(g_data.addrinfo);
	exit(0);
}

void		handle_signal(int signum)
{
	if (signum == SIGINT)
		stop_ping();
}
