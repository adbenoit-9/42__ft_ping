/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:21:49 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/01 14:27:18 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void    stop_ping(void)
{
    printf("\n--- localhost ping statistics ---\n");
    exit(0);
}

void    handle_signal(int signum)
{
    if (signum == SIGINT)
        stop_ping();
}
