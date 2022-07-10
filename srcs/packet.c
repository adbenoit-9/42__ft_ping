/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:52:44 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/10 19:57:03 by adbenoit         ###   ########.fr       */
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

static struct icmp	init_icmp_header()
{
	struct icmp	icmphdr;

	memset(&icmphdr, 0, sizeof(struct icmp));
	icmphdr.icmp_type = ECHO_REQUEST_TYPE;
	icmphdr.icmp_code = ECHO_REQUEST_CODE;
	icmphdr.icmp_id = getpid();
	icmphdr.icmp_seq = 1;
	icmphdr.icmp_cksum = checksum((unsigned short *)&icmphdr, sizeof(struct icmp));
	return (icmphdr);
}

/* https://book.huihoo.com/iptables-tutorial/x1078.htm */

t_echo_packet	icmp_echo_packet(void)
{
	t_echo_packet	packet;

	memset(&packet, 0, sizeof(t_echo_packet));
	// packet.ip = init_ip_header();
	packet.icmp = init_icmp_header();
	printf("%ld\n", sizeof(struct icmp));
	return (packet);
}
