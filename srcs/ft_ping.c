/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:20:21 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/08 18:19:26 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void    set_header(void *packet)
{
    // version = 4
    // IHL 20 = 5 * 4
    // DSCP = 
    // ECN = 
    // total length = HEADER_SIZE + PACKET_SIZE = 84
}

void    set_checksum(void *packet)
{
    ((char *)packet)[0] = 0;
    ((char *)packet)[1] = 0;
}

void    *set_packet(void)
{
    void    *packet;

    packet = malloc(HEADER_SIZE);
    packet = memset(packet, 0, HEADER_SIZE);
    ((char *)packet)[0] = ECHO_REQUEST_TYPE;
    ((char *)packet)[1] = ECHO_REQUEST_CODE;
    set_checksum(packet + 2);
    set_header(packet + 4);
    return (packet);
}

int ft_ping(void)
{
    int             fd;
    size_t          icmp_seq;
    ssize_t         ret;
    struct msghdr   mess;
    char            data_sent[256];
    
    fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (fd == -1) {
        perror("");
        ft_perror(ERR_SOCK, NULL, 0);
    }
    printf("PING %s (%s) %d(%d) bytes of data.\n", g_data.host, g_data.ip,
            PACKET_SIZE, PACKET_SIZE + HEADER_SIZE);
    icmp_seq = 1;
    while (1)
    {
        sendto(fd, data_sent, sizeof(data_sent), 0, g_data.sockaddr, sizeof(g_data.sockaddr));
        perror("");
        ret = recvmsg(fd, &mess, 0);
        printf("%ld\n", ret);
        perror("");
        ++icmp_seq;
        exit(1);
    }
    return (0);
}
