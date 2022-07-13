/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:27:25 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/13 12:18:34 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

char	*ft_sterror(int error, char *arg, char option)
{
	static char	str[4096];
	char		*msg[] = {NOMEM_MSG, SOCKERR_MSG, TRANSMERR_MSG, NOHOST_MSG};
	
	if (error <= NOHOST)
		sprintf(str, "%s", msg[error]);
	else if (error == BADHOST)
		sprintf(str, BADHOST_MSG, arg);
	else if (error == BADAF)
		sprintf(str, BADAF_MSG, arg);
	else if (error == BADARG)
		sprintf(str, BADARG_MSG, arg);
	else if (error == BADOPT)
	{
		sprintf(str, BADOPT_MSG, option);
		print_help();
	}
	else if (error == ARGOOR)
		sprintf(str, ARGOOR_MSG, arg, 1, LLONG_MAX);
	return (str);
}

int	ft_perror(char *error)
{
	dprintf(STDERR_FILENO, "%s", error);
	return (0);
}

int	fatal_error(int error, char *arg, char option)
{
	int		status;

	ft_perror(ft_sterror(error, arg, option));
	clean();
	status = error < NOHOST ? USAGE_ERR : ERROR;
	exit(status);
}
