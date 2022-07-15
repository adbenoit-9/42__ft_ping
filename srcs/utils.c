/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:35:48 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/15 20:45:37 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	clean(void)
{
	free(g_data.host);
	if (g_data.sockfd != -1)
		close(g_data.sockfd);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
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

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	while (s1[i])
		++i;
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (0);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		++i;
	}
	copy[i] = '\0';
	return (copy);
}
