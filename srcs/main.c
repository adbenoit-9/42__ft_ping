/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:36 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/11 15:13:22 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_ping_data	g_data;

static t_ping_data	init_ping_data(void)
{
	t_ping_data	data;

	data.host = NULL;
	data.ip = NULL;
	data.flag = 0;
	data.count = -1;
	data.sockfd = -1;
	memset(&data.sockaddr, 0, sizeof(data.sockaddr));
	return (data);
}

static int	set_ipaddr(void)
{
	struct addrinfo		hints;
	struct addrinfo		*res;
	struct sockaddr_in	*addr;
	int					ret;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;
	hints.ai_flags = 0;
	ret = getaddrinfo(g_data.host, NULL, &hints, &res);
	if (ret != 0)
		ft_perror(BADHOST, g_data.host, 0);
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
		ft_perror(NOHOST, NULL, 0);
	g_data = init_ping_data();
	parser(av + 1);
	set_ipaddr();
	ret = inet_pton(AF_INET, g_data.ip, &buf);
	if (ret == 0)
		ft_perror(BADAF, g_data.host, 0);
	else if (ret < 0)
		ft_perror(BADHOST, g_data.host, 0);
	g_data.sockaddr = (struct sockaddr *)&buf;
	init_socket();
	signal(SIGINT, handle_signal);
	signal(SIGALRM, handle_signal);
	g_data.icmp_packet = request_packet();
    ping();
	while (true)
		recv_echo_reply();
	return (0);
}
