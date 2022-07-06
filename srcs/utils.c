/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:35:48 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/06 12:04:03 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	clean(void)
{
    free(g_data.host);
    freeaddrinfo(g_data.addrinfo);
}

int		print_help(void)
{
	printf("\nUsage\n");
	printf(" ping [options] <destination>\n");
	printf("Options:\n");
	printf("-h                 print help and exit\n");
	printf("-v                 verbose output\n");
	printf("-4                 use IPv4\n");
	printf("-6                 use IPv6\n");
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
