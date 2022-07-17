/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:51:15 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/17 13:42:09 by adbenoit         ###   ########.fr       */
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
	msg.msg_flags = 0;
	return (msg);
}

bool	ckeck_icmphdr(struct icmp icmphdr)
{
	unsigned short	cksum;

	cksum = icmphdr.icmp_cksum;
	icmphdr.icmp_cksum = 0;
	if (checksum((unsigned short *)&icmphdr, sizeof(icmphdr)) != cksum)
		return (false);
	return (true);
}

int	recv_echo_reply(struct timeval req_time)
{
	ssize_t			len;
	struct msghdr	msg;
	struct timeval	res_time;
	double			time_ms;

	msg = init_msg();
	len = -1;
	while (len == -1 && !STATUS_ISSET(RTIMEDOUT) && STATUS_ISSET(WAIT_REPLY))
		len = recvmsg(g_data.sockfd, &msg, 0);
# ifdef DEBUG
	if (len == -1) {
		printf("%s[Reception failed]%s %s\n", S_RED, S_NONE, strerror(errno));
		print_msg(msg);
	}
	else {
		printf("%s[Packet received]%s %zd bytes\n", S_YELLOW, S_NONE, len);
		print_ip(R_PACKET.iphdr);
		print_icmp(R_PACKET.icmphdr);
	}
# endif
	alarm(0);
	if (STATUS_ISSET(RTIMEDOUT))
		return (ETIMEDOUT);
	if (!ckeck_icmphdr(R_PACKET.icmphdr)) {
		++g_data.stats.nerror;
		return (EP_REPLY);
	}
	++g_data.stats.nrecv;
	if (gettimeofday(&res_time, NULL) == -1)
		fatal_error(errno, "gettimeofday", 0);
	time_ms = tv_to_ms(res_time) - tv_to_ms(req_time);
	set_time_stats(time_ms);
	if (!FLAG_ISSET(F_QUIET))
	{
		printf("%zd bytes from %s (%s): icmp_seq=%d ttl=%d time=%.3f ms\n",
			len, g_data.host, g_data.ip, S_PACKET.header.icmp_seq,
			R_PACKET.iphdr.ip_ttl, time_ms);
	}
	return (SUCCESS);
}
