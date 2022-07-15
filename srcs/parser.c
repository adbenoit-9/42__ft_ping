/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:42:56 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/15 17:15:33 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static int	flag_value(char flag)
{
	int		values[] = {HELP, VERBOSE, COUNT, QUIET};

	for (size_t i = 0; FLAGS[i]; i++)
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
			fatal_error(BADOPT, NULL, flags[i]);
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
		if ((g_data.flag & COUNT) && g_data.count == -1) {
			g_data.count = atoll(arg[i]);
			if (!ft_isnumber(arg[i]))
				fatal_error(BADARG, arg[i], 0);
			else if (g_data.count <= 0)
				fatal_error(ARGOOR, arg[i], 0);
		}
		else if (arg[i][0] == '-')
			set_flag(arg[i] + 1);
		else
			host = arg[i];
	}
	if ((g_data.flag & COUNT) && g_data.count == -1)
		fatal_error(NOARG, NULL, 'c');
	if (!host)
		fatal_error(NOHOST, NULL, 0);
	g_data.host = ft_strdup(host);
	if (!g_data.host)
		fatal_error(ENOMEM, NULL, 0);
	return (SUCCESS);
}
