/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:35:48 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/05 19:53:12 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int	print_help(void)
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
	printf("flags: %d\n", info.ai_flags);
    printf("family: %d\n", info.ai_family);
    printf("socktype: %d\n", info.ai_socktype);
    printf("protocol: %d\n", info.ai_protocol);
    printf("addrlen: %u\n", info.ai_addrlen);
    printf("addr data: %s\n", info.ai_addr->sa_data);
    printf("addr family: %d\n", info.ai_addr->sa_family);
    printf("canonname: %s\n", info.ai_canonname);
}