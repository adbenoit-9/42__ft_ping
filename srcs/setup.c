/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:45:13 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/17 13:42:20 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_ping_data	init_ping_data(void)
{
	t_ping_data	data;

	data.host = NULL;
	bzero(data.ip, INET_ADDRSTRLEN);
	data.flag.count = -1;
	data.flag.ttl = -1;
	data.flag.isset = NONE;
	data.status = NONE;
	data.stats.nrecv = 0;
	data.stats.nerror = 0;
	data.stats.nsent = 0;
	data.stats.min_time = 0.;
	data.stats.max_time = 0.;
	data.stats.sum_time = 0.;
	data.stats.sum_square_time = 0.;
	gettimeofday(&data.stats.begin_time, NULL);
	data.sockfd = -1;
	data.pid = getpid();
	bzero(&data.sockaddr, sizeof(data.sockaddr));
	return (data);
}

void	clear_data(void)
{
	free(g_data.host);
	if (g_data.sockfd != -1)
		close(g_data.sockfd);
}

int	setup_address(void)
{
	struct addrinfo	hints;
	struct addrinfo	*res;
	struct in_addr	src;
	int				ret;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;
	hints.ai_flags = 0;
	ret = getaddrinfo(g_data.host, NULL, &hints, &res);
	if (ret == EAI_FAMILY)
		fatal_error(EP_FAMILY, g_data.host, 0);
	else if (ret == EAI_NODATA)
		fatal_error(EP_NODATA, g_data.host, 0);
	else if (ret != 0)
		fatal_error(EP_NONAME, g_data.host, 0);
	memcpy(&g_data.sockaddr, res->ai_addr, sizeof(struct sockaddr));
	src = ((struct sockaddr_in *)res->ai_addr)->sin_addr;
	if (!inet_ntop(AF_INET, &src, g_data.ip, INET_ADDRSTRLEN))
		fatal_error(errno, g_data.host, 0);
	freeaddrinfo(res);
	return (0);
}

void	setup_socket(void)
{
	int				ttl;

	g_data.sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (g_data.sockfd == -1)
		fatal_error(errno, "socket", 0);
	ttl = FLAG_ISSET(F_TTL) ? g_data.flag.ttl : DEFAULT_TTL;
	if (setsockopt(g_data.sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) == -1)
		fatal_error(errno, "setsockopt", 0);
}
