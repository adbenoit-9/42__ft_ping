/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:35:48 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/15 20:06:15 by adbenoit         ###   ########.fr       */
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

int	print_packet(t_packet packet)
{
	char	src[INET_ADDRSTRLEN];
	char	dst[INET_ADDRSTRLEN];

	if (sizeof(packet) == sizeof(R_PACKET))
	{
		if (!inet_ntop(AF_INET, &R_PACKET.iphdr.ip_src, src, INET_ADDRSTRLEN))
			ft_perror(ft_strerror(errno), "inet_ntop");
		if (!inet_ntop(AF_INET, &R_PACKET.iphdr.ip_dst, dst, INET_ADDRSTRLEN))
			ft_perror(ft_strerror(errno), "inet_ntop");
		printf("%d bytes from %s: Time to live exceeded\n",
			packet.echo.reply.iphdr.ip_len, src);
		printf("Vr HL TOS  Len    ID   off TTL Pro  cks      Src      Dst\n");
		printf("%2d %2d %3.2d %4d %5d %.4d %3.2d %3.2d %4x %s %2s\n\n",
			packet.echo.reply.iphdr.ip_v, packet.echo.reply.iphdr.ip_hl,
			packet.echo.reply.iphdr.ip_tos, packet.echo.reply.iphdr.ip_len,
			packet.echo.reply.iphdr.ip_id, packet.echo.reply.iphdr.ip_off,
			packet.echo.reply.iphdr.ip_ttl, packet.echo.reply.iphdr.ip_p,
			packet.echo.reply.iphdr.ip_sum,
			src, dst);
	}
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
		if (!ft_isdigit(str[i]))
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
