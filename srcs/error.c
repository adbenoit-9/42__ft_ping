/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:27:25 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/11 01:48:28 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int	ft_perror(int code_err, char *arg, char option)
{
    char  *msg[] = {NOMEM_MSG, SOCKERR_MSG, NOHOST_MSG};
    int   status;

    if (code_err <= NOHOST)
      dprintf(STDERR_FILENO, "%s", msg[code_err]);
    else if (code_err == BADHOST)
      dprintf(STDERR_FILENO, BADHOST_MSG, arg);
    else if (code_err == BADAF)
      dprintf(STDERR_FILENO, BADAF_MSG, arg);
    else if (code_err == BADARG)
      dprintf(STDERR_FILENO, BADARG_MSG, arg);
    else if (code_err == BADOPT)
    {
      dprintf(STDERR_FILENO, BADOPT_MSG, option);
      print_help();
    }
    else if (code_err == ARGOOR)
        dprintf(STDERR_FILENO, ARGOOR_MSG, arg, 1, LLONG_MAX);
	status = code_err < NOHOST ? USAGE_ERR : ERROR;
	exit(status);
}
