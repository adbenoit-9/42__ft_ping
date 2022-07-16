/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:42:56 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/16 16:17:44 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static int	flag_value(char flag)
{
	int		values[] = {F_HELP, F_VERBOSE, F_COUNT, F_QUIET, F_TTL};

	for (size_t i = 0; FLAGS[i]; i++)
		if (FLAGS[i] == flag)
			return (values[i]);
	return (-1);
}

static void	set_option_value(const char *str)
{
	long long int opt;

	opt = atoll(str);
	if (opt == LLONG_MAX &&
			ft_strcmp(str, "9223372036854775807"))
		fatal_error(EP_RESOOR, str, 0);
	if (!ft_isnumber(str))
		fatal_error(EP_BADARG, str, 0);
	if (FLAG_ISSET(F_COUNT) && g_data.count == -1) {
		g_data.count = opt;
		if (g_data.count <= 0)
			fatal_error(EP_ARGOOR, str, 'c');
	}
	else if (FLAG_ISSET(F_TTL) && g_data.ttl == -1) {
		g_data.ttl = opt;
		if (g_data.ttl < 0 || g_data.ttl > 255)
			fatal_error(EP_ARGOOR, str, 't');
	}
	return ;
}

static int	set_flag(char *flags)
{
	int	new_flag;

	for (int i = 0; flags[i]; i++)
	{
		new_flag = flag_value(flags[i]);
		if (new_flag == -1)
			fatal_error(EP_BADOPT, NULL, flags[i]);
		g_data.flag |= new_flag;
		if (new_flag == F_HELP)
		{
			print_usage();
			exit(SUCCESS);
		}
		else if (new_flag == F_COUNT || new_flag == F_TTL) {
			return (i + 1);
		}
	}
	return (0);
}

bool	parser(char **arg)
{
	char	*host;
	int		ret;

	host = NULL;
	for (size_t i = 0; arg[i]; i++)
	{
		if (FLAG_ISSET(F_COUNT) && g_data.count == -1) {
			set_option_value(arg[i]);
		}
		else if (arg[i][0] == '-')
		{
			ret = set_flag(arg[i] + 1);
			if (ret && arg[i][ret + 1])
				set_option_value(arg[i] + ret + 1);
		}
		else {
			host = arg[i];
		}
	}
	if (FLAG_ISSET(F_COUNT) && g_data.count == -1)
		fatal_error(EP_NOARG, NULL, 'c');
	if (!host)
		fatal_error(EP_NODATA, NULL, 0);
	g_data.host = ft_strdup(host);
	if (!g_data.host)
		fatal_error(ENOMEM, NULL, 0);
	return (SUCCESS);
}
