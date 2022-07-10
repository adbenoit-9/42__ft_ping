/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:42:56 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/10 17:32:59 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static int	flag_value(char flag)
{
	size_t	i;
	int		values[] = {HELP, VERBOSE, COUNT, QUIET};

	i = 0;
	for (; FLAGS[i]; i++)
		if (FLAGS[i] == flag)
			return (values[i]);
	return (-1);
}

int	parser(char **arg)
{
	char	*host;
	int		new_flag;

	host = NULL;
	for (size_t i = 0; arg[i]; i++)
	{
		if ((g_data.flag & COUNT) == COUNT && g_data.count == -1)
		{
			g_data.count = atoll(arg[i]);
			if (!ft_isnumber(arg[i]) || g_data.count <= 0)
				ft_perror(ERR_ARG, arg[i], 0);
		}
		else if (arg[i][0] == '-')
		{
			for (int j = 1; arg[i][j]; j++)
			{
				new_flag = flag_value(arg[i][j]);
				if (new_flag == -1)
					ft_perror(ERR_OPTION, NULL, arg[i][j]);
				g_data.flag |= new_flag;
				if (new_flag == HELP)
					return (0);
			}
		}
		else
			host = arg[i];
	}
	if (!host)
		ft_perror(ERR_USAGE, NULL, 0);
	g_data.host = strdup(host);
	if (!g_data.host)
		return (ft_perror(ENOMEM, NULL, 0));
	return (0);
}
