/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   response.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:51:15 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/13 17:21:10 by adbenoit         ###   ########.fr       */
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
	if (checksum((unsigned short *)&icmphdr, sizeof(icmphdr)) != cksum)
		return (false);
	return (true);
}

double	time_interval(struct timeval start, struct timeval end)
{
	size_t sec;
	size_t usec;
	
	sec = end.tv_sec - start.tv_sec;
	usec = end.tv_usec - start.tv_usec;
	return ((double)sec * 1000 + (double)usec / 1000);
}

bool	recv_echo_reply(struct timeval req_time)
{
	ssize_t			len;
	struct msghdr	msg;
	struct timeval	res_time;
	double			time_ms;

	msg = init_msg();
	len = recvmsg(g_data.sockfd, &msg, 0);
	gettimeofday(&res_time, NULL);
	time_ms = time_interval(req_time, res_time);
	if (g_data.stats.nsent == 1)
	{
		g_data.stats.min_time = time_ms;
		g_data.stats.max_time = time_ms;
	}
	g_data.stats.min_time = time_ms < g_data.stats.min_time ? time_ms : g_data.stats.min_time;
	g_data.stats.max_time = time_ms > g_data.stats.max_time ? time_ms : g_data.stats.max_time;
	g_data.stats.total_time += time_ms;
#ifdef DEBUG
	if (len == -1) {
		printf("%s[Reception failed]%s %s\n", S_RED, S_NONE, strerror(errno));
		print_msg(msg);
	}
	else {
		printf("%s[Packet received]%s %zd bytes\n", S_YELLOW, S_NONE, len);
		print_ip(R_PACKET.iphdr);
		print_icmp(R_PACKET.icmphdr);
	}
#endif
	if (len == -1) {
		if (errno == EWOULDBLOCK || errno == EAGAIN)
			printf("Request timeout\n");
		else
			ft_perror(strerror(errno), "recv");
		return (false);
	}
	if (!ckeck_icmphdr(R_PACKET.icmphdr)) {
		printf("Request timeout\n");
		return (false);
	}
	++g_data.stats.nrecv;
	if (!(g_data.flag & QUIET))
	{
		printf("%zd bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n",
			len, g_data.ip, R_PACKET.icmphdr.icmp_seq,
			R_PACKET.iphdr.ip_ttl, time_ms);
	}
	return (true);
}
