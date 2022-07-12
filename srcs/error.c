/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:27:25 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/12 18:52:49 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int	ft_perror(int error, char *arg, char option)
{
	char  *msg[] = {NOMEM_MSG, SOCKERR_MSG, TRANSMERR_MSG, NOHOST_MSG};
	int   status;

	if (error <= NOHOST)
		dprintf(STDERR_FILENO, "%s", msg[error]);
	else if (error == BADHOST)
		dprintf(STDERR_FILENO, BADHOST_MSG, arg);
	else if (error == BADAF)
		dprintf(STDERR_FILENO, BADAF_MSG, arg);
	else if (error == BADARG)
		dprintf(STDERR_FILENO, BADARG_MSG, arg);
	else if (error == BADOPT)
	{
		dprintf(STDERR_FILENO, BADOPT_MSG, option);
		print_help();
	}
	else if (error == ARGOOR)
			dprintf(STDERR_FILENO, ARGOOR_MSG, arg, 1, LLONG_MAX);
	status = error < NOHOST ? USAGE_ERR : ERROR;
	exit(status);
}
