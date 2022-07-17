/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:51:15 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/17 18:22:23 by adbenoit         ###   ########.fr       */
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

static int	ckeck_reply(struct icmp icmphdr)
{
	g_data.status &= ~NOT_RECV;
	if (STATUS_ISSET(RTIMEDOUT))
		return (ETIMEDOUT);
	if (ICMP_ERRORTYPE(icmphdr.icmp_type))
	{
		++g_data.stats.nerror;
		return (icmphdr.icmp_type);
	}
	else if (icmphdr.icmp_id != g_data.pid)
	{
		g_data.status |= NOT_RECV;
		return (EP_BADID);
	}
	else if (icmphdr.icmp_seq != g_data.stats.nsent)
	{
		g_data.status |= NOT_RECV;
		return (EP_BADSEQ);
	}
	return (SUCCESS);
}

int	recv_echo_reply(struct timeval req_time)
{
	ssize_t			len;
	struct msghdr	msg;
	struct timeval	res_time;
	int				ret;

	msg = init_msg();
	len = -1;
	while (len == -1 && !STATUS_ISSET(RTIMEDOUT) && STATUS_ISSET(WAIT_REPLY)) {
		len = recvmsg(g_data.sockfd, &msg, 0);
	}
# ifdef DEBUG
	if (len == -1) {
		printf("%s[Reception failed]%s %s\n", S_RED, S_NONE, strerror(errno));
		debug_msg(msg);
	}
	else {
		printf("%s[Packet received]%s %zd bytes\n", S_YELLOW, S_NONE, len);
		debug_ip(R_PACKET.iphdr);
		debug_icmp(R_PACKET.icmphdr);
	}
# endif
	alarm(0);
	ret = ckeck_reply(R_PACKET.icmphdr);
	if (ret != SUCCESS)
		return (ret);
	++g_data.stats.nrecv;
	if (gettimeofday(&res_time, NULL) == -1)
		fatal_error(errno, "gettimeofday", 0);
	g_data.time_ms = tv_to_ms(res_time) - tv_to_ms(req_time);
	set_time_stats(g_data.time_ms);
	return (SUCCESS);
}
