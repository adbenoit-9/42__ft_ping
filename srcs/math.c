/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:51:24 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/15 20:54:04 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static double	ft_sqrt(double n)
{
	double	sqrt;
	double	tmp;

	if (n < 0.)
		return (-1);
	sqrt = n / 2.;
	while (sqrt * sqrt < n)
		sqrt += 1.;
	if (sqrt * sqrt == n)
		return (sqrt);
	sqrt -= 1.;
	tmp = 0.;
	while (tmp != sqrt)
	{
		tmp = sqrt;
		sqrt = (n / tmp + tmp) / 2.;
	}
	return (sqrt);
}

/* formula  = sqrt(1/n * sum((Xi - mean)^2)) for i in [1, n]
			= sqrt(sum(Xi^2) / n - mean^2) */
double	standard_deviation(double sum_xi, double sum_square_xi, int n)
{
	double	mean_xi;

	mean_xi = sum_xi / n;
	return (ft_sqrt(sum_square_xi / n - mean_xi * mean_xi));
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
