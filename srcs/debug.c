/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:54:29 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/15 13:56:26 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	print_addrinfo(struct addrinfo info)
{
	struct sockaddr_in	*addr;

	printf("flags: %d\n", info.ai_flags);
	printf("family: %d\n", info.ai_family);
	printf("socktype: %d\n", info.ai_socktype);
	printf("protocol: %d\n", info.ai_protocol);
	printf("addrlen: %u\n", info.ai_addrlen);
	addr = (struct sockaddr_in *)info.ai_addr;
	printf("addr %s\n", inet_ntoa((struct in_addr)addr->sin_addr));
	printf("canonname: %s\n", info.ai_canonname);
}

void	print_ip(struct ip iphdr)
{
	printf("-- IP HEADER (size %ld) --\n", sizeof(iphdr));
	printf("ttl: %d\n", iphdr.ip_ttl);
}

void	print_icmp(struct icmp icmphdr)
{
	printf("-- ICMP HEADER (size %ld) --\n", sizeof(icmphdr));
	printf("type: %d\n", icmphdr.icmp_type);
	printf("code: %d\n", icmphdr.icmp_code);
	printf("identifier: %d\n", icmphdr.icmp_id);
	printf("sequence: %d\n", icmphdr.icmp_seq);
	printf("checksum: %d\n", icmphdr.icmp_cksum);
}

void	print_time(struct timeval time)
{
	printf("time: %ld secondes %ld microsecondes\n",
		time.tv_sec, (size_t)time.tv_usec);
}

void	print_msg(struct msghdr msg)
{
	printf("-- MSG HEADER (size %ld) --\n", sizeof(struct msghdr));
	printf("data pointer: %p\n", msg.msg_iov[0].iov_base);
	printf("data length: %zd\n", msg.msg_iov[0].iov_len);
	printf("iov array length: %ld\n", (size_t)msg.msg_iovlen);
	printf("flags: %d\n", msg.msg_flags);
}
