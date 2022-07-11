/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply_icmp_requestc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 00:31:14 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/11 00:31:45 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void    recv_echo_reply(void)
{
    ssize_t         len;
    struct iovec    iov;
    struct msghdr   msg;
    t_icmp_packet   icmp_packet;
    // char            buf[4098];

    while (true)
    {
        sleep(30);
        memset(&msg, 0, sizeof(msg));
        memset(&iov, 0, sizeof(iov));
        iov.iov_base = &recv_packet;
        iov.iov_len = 1;
        msg.msg_name = NULL;
        msg.msg_namelen = 0;
        // msg.msg_name = &g_data.sockaddr;
        // msg.msg_namelen = sizeof(g_data.sockaddr);
        msg.msg_iov = &iov;
        msg.msg_control = NULL;
        msg.msg_controllen = 0;
        errno = 0;
        len = recvmsg(g_data.sockfd, &msg, 0);
#ifdef DEBUG
        if (len == -1)
            printf("\n%sTransmission failed !%s\n%s\n\n", S_RED, S_NONE, strerror(errno));
        else
        {
            printf("\n%sPacket received (%zd bytes) !%s\n", S_YELLOW, len, S_NONE);
            print_icmp(recv_packet.header);
        }
#endif
        if (len == -1)
            ft_perror(TRANSMERR, NULL, 0);
    }
}
