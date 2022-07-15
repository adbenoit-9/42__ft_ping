/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:51:24 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/15 14:06:01 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

double	ft_sqrt(double n)
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
