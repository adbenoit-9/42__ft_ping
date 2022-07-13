/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:36 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/13 14:57:32 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_ping_data	g_data;

static t_ping_data	init_ping_data(void)
{
	t_ping_data	data;

	data.host = NULL;
	bzero(data.ip, INET_ADDRSTRLEN);
	data.flag = 0;
	data.count = -1;
	data.state.nrecv = 0;
	data.state.nsent = 0;
	data.sockfd = -1;
	data.pid = getpid();
	data.state.status = WAIT;
	bzero(&data.sockaddr, sizeof(data.sockaddr));
	return (data);
}

static int	init_address(void)
{
	struct addrinfo		hints;
	struct addrinfo		*res;
	struct in_addr		src;
	int					ret;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;
	hints.ai_flags = 0;
	ret = getaddrinfo(g_data.host, NULL, &hints, &res);
	if (ret != 0)
		fatal_error(ret, g_data.host, 0);
	memcpy(&g_data.sockaddr, res->ai_addr, sizeof(struct sockaddr));
	src = ((struct sockaddr_in *)res->ai_addr)->sin_addr;
	if (!inet_ntop(AF_INET, &src, g_data.ip, INET_ADDRSTRLEN))
		fatal_error(ret, g_data.host, 0);
	freeaddrinfo(res);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		fatal_error(NOHOST, NULL, 0);
	g_data = init_ping_data();
	parser(av + 1);
	init_address();
	init_socket();
	signal(SIGINT, handle_signal);
	signal(SIGALRM, handle_signal);
	printf("PING %s (%s) %d(%d) bytes of data.\n", g_data.host, g_data.ip,
		PACKET_SIZE, PACKET_SIZE + HEADER_SIZE);
	g_data.request_packet = request_packet();
	ping();
	while (true)
		recv_echo_reply();
	return (0);
}
