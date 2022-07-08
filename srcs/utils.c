/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:35:48 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/08 14:47:49 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	clean(void)
{
    free(g_data.host);
}

int		print_help(void)
{
	printf("\nUsage\n");
	printf(" ./ft_ping [options] <destination>\n");
	printf("Options:\n");
	printf("-h                 print help and exit\n");
	printf("-v                 verbose output\n");
	printf("-c <count>         stop after <count> replies\n");
	printf("\n");
	return (0);
}

void	print_addrinfo(struct addrinfo info)
{
	struct sockaddr_in *addr;

	printf("flags: %d\n", info.ai_flags);
    printf("family: %d\n", info.ai_family);
    printf("socktype: %d\n", info.ai_socktype);
    printf("protocol: %d\n", info.ai_protocol);
    printf("addrlen: %u\n", info.ai_addrlen);
	addr = (struct sockaddr_in *)info.ai_addr;
    printf("addr %s\n", inet_ntoa((struct in_addr)addr->sin_addr));
    printf("canonname: %s\n", info.ai_canonname);
}

int		ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		++i;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}
