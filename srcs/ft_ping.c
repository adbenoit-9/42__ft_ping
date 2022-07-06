/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:20:21 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/06 16:00:32 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int ft_ping(void)
{
    int fd;
    // size_t icmp_seq;
    // ssize_t ret;
    // struct msghdr   mess;
    // char data_sent[256];
    
    fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (fd == -1)
        ft_perror(ERR_SOCK, NULL, 0);
    printf("PING %s (%s) %d(%d) bytes of data.\n", g_data.host, g_data.ip,
            PACKET_SIZE, PACKET_SIZE + HEADER_SIZE);
    // icmp_seq = 1;
    // while (1)
    // {
        // sendto(g_data.fd, data_sent, sizeof(data_sent), 0, g_data.sockaddr, sizeof(g_data.sockaddr));
        // perror("");
        // ret = recvmsg(g_data.fd, &mess, 0);
        // printf("%ld\n", ret);
        // perror("");
    //     ++icmp_seq;
    // }
    return (0);
}
