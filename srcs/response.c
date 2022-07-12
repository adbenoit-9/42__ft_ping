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

static struct msghdr   init_msg(void)
{
    struct msghdr   msg;
    static struct iovec iov[1];

    bzero(&iov, sizeof(iov));
    bzero(&msg, sizeof(msg));
    bzero(&recv_packet, sizeof(recv_packet));
    iov[0].iov_base = &recv_packet;
    iov[0].iov_len = sizeof(recv_packet);
    msg.msg_iov = iov;
    msg.msg_iovlen = 1;
    return (msg);
}

void    recv_echo_reply(void)
{
    ssize_t         len;
    struct msghdr   msg;

    while (true)
    {
        msg = init_msg();
        len = recvmsg(g_data.sockfd, &msg, 0);
#ifdef DEBUG
        if (len == -1) {
            printf("%s[Reception failed]%s %s\n", S_RED, S_NONE, strerror(errno));
            print_msg(msg);
        }
        else {
            printf("%s[Packet received]%s %zd bytes\n", S_YELLOW, S_NONE, len);
            print_icmp(recv_packet.header);
        }
#endif
        if (len == -1)
            ft_perror(TRANSMERR, NULL, 0);
    }
}
