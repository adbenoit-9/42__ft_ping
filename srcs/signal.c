/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:21:49 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/16 17:32:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	handle_signal(int signum)
{
	if (signum == SIGINT)
		ping_statistics();
	else if (signum == SIGALRM && !STATUS_ISSET(STOP_SENDING))
		g_data.status |= RTIMEDOUT;
}
