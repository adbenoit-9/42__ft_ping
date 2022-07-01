/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:36 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/01 18:16:04 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_data  g_data;

int main(int ac, char **av)
{
    struct in_addr  buf;
    int             ret;

    if (ac == 1)
        ft_strerror(ERR_USAGE, NULL, 0);
    g_data.host = NULL;
    g_data.af = -1;
    bzero(g_data.flags, NB_FLAGS + 1);
    parser(av + 1);
    if (strchr(g_data.flags, 'h'))
    {
        print_help();
        exit(0);
    }
    getaddrinfo(g_data.host, NULL, NULL, &g_data.addrinfo);
    if (strchr(g_data.flags, '4'))
        g_data.af = AF_INET;
    else if (strchr(g_data.flags, '6'))
        g_data.af = AF_INET6;
    else
        g_data.af = g_data.addrinfo->ai_family;
    signal(SIGINT, handle_signal);
    ret = inet_pton(g_data.af, g_data.host, &buf);
    // ERROR PAS BONNES ATTENTION
    if (ret == 0)
        ft_strerror(ERR_AF, g_data.host, 0);
    else if (ret < 0)
        ft_strerror(ERR_USAGE, g_data.host, 0);
    // printf("PING %s (%s): 56 data bytes\n", av[ac - 1], host);
    while (1)
    {
        ft_ping("");
    }
    return (0);
}
