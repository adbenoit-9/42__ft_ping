/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:52:44 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/10 18:41:52 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/* https://www.rfc-editor.org/rfc/rfc792 */

// static struct iphdr	init_ip_header(void)
// {
// 	struct iphdr	ip_header;

// 	memset(&ip_header, 0, sizeof(struct iphdr));
// 	ip_header.version = VERSION;
// 	ip_header.ihl = 5; // 5 * 4 ?
// 	// ip_header.tos = 0;
// 	ip_header.tot_len = DATA_SIZE + HEADER_SIZE;
// 	// ip_header.frag_off = 
// 	ip_header.ttl = DEFAULT_TTL;
// 	ip_header.protocol = IPPROTO_ICMP;
// 	// ip_header.check = 0;
// 	// ip_header.saddr = 
// 	// ip_header.daddr = hton()
// 	return (ip_header);
// }

static struct icmphdr	init_icmp_header()
{
	struct icmphdr	icmp_header;

	memset(&icmp_header, 0, sizeof(struct icmphdr));
	icmp_header.type = ECHO_REQUEST_TYPE;
	icmp_header.code = ECHO_REQUEST_CODE;
	icmp_header.un.echo.id = getpid();
	icmp_header.un.echo.sequence = 1;
	icmp_header.checksum = checksum((unsigned short *)&icmp_header, sizeof(struct icmphdr));
	return (icmp_header);
}

/* https://book.huihoo.com/iptables-tutorial/x1078.htm */

t_echo_packet	icmp_echo_packet(void)
{
	t_echo_packet	packet;

	memset(&packet, 0, sizeof(t_echo_packet));
	// packet.ip = init_ip_header();
	packet.icmp = init_icmp_header();
	printf("%ld\n", sizeof(struct icmphdr));
	return (packet);
}
