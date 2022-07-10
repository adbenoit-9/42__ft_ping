/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:36 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/10 17:58:08 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_data	g_data;

static int	init_data(void)
{
	g_data.host = NULL;
	g_data.ip = NULL;
	g_data.flag = 0;
	g_data.count = -1;
	// g_data.addrinfo = NULL;
	memset(&g_data.sockaddr, 0, sizeof(g_data.sockaddr));
	// g_data.fd = -1;
	return (0);
}

static int	set_ipaddr(void)
{
	struct addrinfo		hints;
	struct addrinfo		*res;
	struct sockaddr_in	*addr;
	int					ret;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW; // sock_raw bypass TCP/IP 
	hints.ai_protocol = IPPROTO_ICMP;
	hints.ai_flags = 0;
	ret = getaddrinfo(g_data.host, NULL, &hints, &res);
	if (ret != 0)
		ft_perror(ERR_USAGE, g_data.host, 0);
	addr = (struct sockaddr_in *)res->ai_addr;
	g_data.ip = inet_ntoa((struct in_addr)addr->sin_addr);
	freeaddrinfo(res);
	return (0);
}

int	main(int ac, char **av)
{
	struct in_addr	buf;
	int				ret;

	if (ac == 1)
		ft_perror(ERR_USAGE, NULL, 0);
	init_data();
	parser(av + 1);
	set_ipaddr();
	signal(SIGINT, handle_signal);
	ret = inet_pton(AF_INET, g_data.ip, &buf);
	if (ret == 0)
		ft_perror(ERR_AF, g_data.host, 0);
	else if (ret < 0)
		ft_perror(ERR_USAGE, g_data.host, 0);
	g_data.sockaddr = (struct sockaddr *)&buf;
	ft_ping();
	return (0);
}
