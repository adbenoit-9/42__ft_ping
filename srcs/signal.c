/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:21:49 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/15 15:19:41 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	handle_signal(int signum)
{
	if (signum == SIGINT)
		ping_statistics();
	else if (signum == SIGALRM)
		g_data.status = TIMEOUT;
}
