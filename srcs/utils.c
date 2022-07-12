/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:35:48 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/12 22:58:05 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	clean(void)
{
	free(g_data.host);
	if (g_data.sockfd != -1)
		close(g_data.sockfd);
}

int	print_help(void)
{
	printf("\nUsage\n");
	printf(" ./ft_ping [options] <destination>\n");
	printf("\nOptions:\n");
	printf("-h                 print help and exit\n");
	printf("-v                 verbose output\n");
	printf("-c <count>         stop after <count> replies\n");
	printf("-q                 quiet output\n");
	printf("\n");
	return (0);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		++i;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}

/* Algorithm computes the checksum with an inner
loop that sums 16-bits (short int) at a time in a 32-bit accumulator.
https://www.rfc-editor.org/rfc/rfc1071#section-4.1 */

unsigned short	checksum(unsigned short *addr, size_t len)
{
	unsigned short	sum;

	sum = 0;
	while (len > 0)
	{
		sum += *addr;
		++addr;
		len -= sizeof(short);
	}
	return (~sum);
}

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

void	print_icmp(struct icmp icmphdr)
{
	printf("-- ICMP HEADER (size %ld) --\n", sizeof(struct icmp));
	printf("type: %d\n", icmphdr.icmp_type);
	printf("code: %d\n", icmphdr.icmp_code);
	printf("identifier: %d\n", icmphdr.icmp_id);
	printf("sequence: %d\n", icmphdr.icmp_seq);
	printf("checksum: %d\n", icmphdr.icmp_cksum);
}

void	print_msg(struct msghdr msg)
{
	printf("-- MSG HEADER (size %ld) --\n", sizeof(struct msghdr));
	printf("data pointer: %p\n", msg.msg_iov[0].iov_base);
	printf("data length: %zd\n", msg.msg_iov[0].iov_len);
	printf("iov array length: %ld\n", (size_t)msg.msg_iovlen);
	printf("flags: %d\n", msg.msg_flags);
}
