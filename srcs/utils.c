/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:35:48 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/04 15:27:12 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int	print_help(void)
{
	printf("\nUsage\n");
	printf(" ping [options] <destination>\n");
	printf("Options:\n");
	printf("-h                 print help and exit\n");
	printf("-4                 use IPv4\n");
	printf("-6                 use IPv6\n");
	printf("\n");
	return (0);
}
