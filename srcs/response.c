/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   response.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:51:15 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/13 12:16:54 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static struct msghdr	init_msg(void)
{
	struct msghdr		msg;
	static struct iovec	iov[1];

	bzero(&iov, sizeof(iov));
	bzero(&msg, sizeof(msg));
	bzero(&R_PACKET, sizeof(R_PACKET));
	iov[0].iov_base = &R_PACKET;
	iov[0].iov_len = sizeof(R_PACKET);
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;
	return (msg);
}

bool	ckeck_icmphdr(struct icmp icmphdr)
{
	unsigned short	cksum;

	cksum = icmphdr.icmp_cksum;
	icmphdr.icmp_cksum = 0;
	if (icmphdr.icmp_type != ICMP_ECHOREPLY)
		return (false);
	else if (icmphdr.icmp_code != 0)
		return (false);
	else if (icmphdr.icmp_id != g_data.pid)
		return (false);
	else if (checksum((unsigned short *)&icmphdr, sizeof(icmphdr)) != cksum)
		return (false);
	else if (icmphdr.icmp_seq != g_data.state.nrecv)
		return (false);
	return (true);
}

void	recv_echo_reply(void)
{
	ssize_t			len;
	struct msghdr	msg;

	msg = init_msg();
	len = recvmsg(g_data.sockfd, &msg, 0);
#ifdef DEBUG
	if (len == -1) {
		printf("%s[Reception failed]%s %s\n", S_RED, S_NONE, strerror(errno));
		print_msg(msg);
	}
	else {
		printf("%s[Packet received]%s %zd bytes\n", S_YELLOW, S_NONE, len);
		print_icmp(R_PACKET.icmphdr);
	}
#endif
	if (len == -1) {
		if (errno == EWOULDBLOCK || errno == EAGAIN)
			ft_perror("Request timeout\n");
		else
			fatal_error(TRANSMERR, NULL, 0);
	}
	else {
		++g_data.state.nrecv;
		if (!ckeck_icmphdr(R_PACKET.icmphdr))
			printf("%spacket corrupted%s\n", S_RED, S_NONE);
	}
}
