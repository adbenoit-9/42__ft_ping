/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:36 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/04 17:56:22 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_data	g_data;

static int	init_data()
{
	g_data.host = NULL;
	g_data.af = -1;
	bzero(g_data.flags, NB_FLAGS + 1);
	return (0);
}

static int	set_af(const char *flags, const struct addrinfo addrinfo)
{
	if (strchr(flags, '4'))
		return (AF_INET);
	else if (strchr(flags, '6'))
		return (AF_INET6);
	return (addrinfo.ai_family);
}

static int	get_adrrinfo(void)
{
	struct addrinfo hints;
	int				ret;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_RAW; // sock_raw bypass TCP/IP => setup my 
	hints.ai_protocol = IPPROTO_ICMP; // IPROTO_ICMPV6 ?
	hints.ai_flags = 0;
	ret = getaddrinfo(g_data.host, NULL, &hints, &g_data.addrinfo);
	if (ret != 0)
		ft_strerror(ret, g_data.host, 0);
	g_data.af = set_af(g_data.flags, *g_data.addrinfo);
	return (0);
}

int			main(int ac, char **av)
{
	struct in_addr	buf;
	int				ret;

	if (ac == 1)
		ft_strerror(ERR_USAGE, NULL, 0);
	init_data();
	parser(av + 1);
	if (strchr(g_data.flags, 'h'))
	{
		free(g_data.host);   
		return (print_help());
	}
	get_adrrinfo();
	signal(SIGINT, handle_signal);
	ret = inet_pton(g_data.af, g_data.host, &buf);
	// ERROR PAS BONNES ATTENTION
	if (ret == 0)
		ft_strerror(ERR_AF, g_data.host, 0);
	else if (ret < 0)
		ft_strerror(ERR_USAGE, g_data.host, 0);
	ft_ping();
	return (0);
}
