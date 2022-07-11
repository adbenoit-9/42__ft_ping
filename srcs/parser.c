/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:42:56 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/11 01:59:53 by adbenoit         ###   ########.fr       */
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

static void	set_flag(char *flags)
{
	int	new_flag;
	
	for (int i = 0; flags[i]; i++)
	{
		new_flag = flag_value(flags[i]);
		if (new_flag == -1)
			ft_perror(BADOPT, NULL, flags[i]);
		g_data.flag |= new_flag;
		if (new_flag == HELP)
		{
			print_help();
			exit(SUCCESS);
		}
	}
	return ;
}

bool	parser(char **arg)
{
	char	*host;

	host = NULL;
	for (size_t i = 0; arg[i]; i++)
	{
		if ((g_data.flag & COUNT) == COUNT && g_data.count == -1)
		{
			g_data.count = atoll(arg[i]);
			if (!ft_isnumber(arg[i]))
				ft_perror(BADARG, arg[i], 0);
			else if (g_data.count <= 0)
				ft_perror(ARGOOR, arg[i], 0);
		}
		else if (arg[i][0] == '-')
			set_flag(arg[i] + 1);
		else
			host = arg[i];
	}
	if (!host)
		ft_perror(NOHOST, NULL, 0);
	g_data.host = strdup(host);
	if (!g_data.host)
		ft_perror(NOMEM, NULL, 0);
	return (SUCCESS);
}
