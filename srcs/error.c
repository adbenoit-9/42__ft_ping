/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:27:25 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/13 17:55:41 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

char	*ft_strerror(int error)
{
	char *msg_err[] = {EPERM_MSG, ENOENT_MSG, ESRCH_MSG, EINTR_MSG, BADAF_MSG,
		ENXIO_MSG,E2BIG_MSG, NONAME_MSG, EBADF_MSG, ECHILD_MSG, EDEADLK_MSG,
		ENOMEM_MSG, EACCES_MSG, EFAULT_MSG, EBUSY_MSG, EEXIST_MSG, EXDEV_MSG,
		ENODEV_MSG, ENOTDIR_MSG, EISDIR_MSG, EINVAL_MSG, ENFILE_MSG, EMFILE_MSG,
		ENOTTY_MSG, ETXTBSY_MSG, EFBIG_MSG, ENOSPC_MSG, ESPIPE_MSG, EROFS_MSG,
		EMLINK_MSG, EPIPE_MSG, EDOM_MSG, ERANGE_MSG, EAGAIN_MSG, EWOULDBLOCK_MSG,
		EINPROGRESS_MSG, EALREADY_MSG, ENOTSOCK_MSG, EDESTADDRREQ_MSG,
		EMSGSIZE_MSG,EPROTOTYPE_MSG, ENOPROTOOPT_MSG, EPROTONOSUPPORT_MSG,
		ESOCKTNOSUPPORT_MSG, ENOTSUP_MSG, EPFNOSUPPORT_MSG, EAFNOSUPPORT_MSG,
		EADDRINUSE_MSG, EADDRNOTAVAIL_MSG, ENETDOWN_MSG, ENETUNREACH_MSG,
		ENETRESET_MSG, ECONNABORTED_MSG, ECONNRESET_MSG, ENOBUFS_MSG, EISCONN_MSG,
		ENOTCONN_MSG, ESHUTDOWN_MSG, ETOOMANYREFS_MSG, ETIMEDOUT_MSG,
		ECONNREFUSED_MSG, ELOOP_MSG, ENAMETOOLONG_MSG, EHOSTDOWN_MSG,
		EHOSTUNREACH_MSG, ENOTEMPTY_MSG, EPROCLIM_MSG, EUSERS_MSG, EDQUOT_MSG,
		ESTALE_MSG, EREMOTE_MSG, EBADRPC_MSG, ERPCMISMATCH_MSG, EPROGUNAVAIL_MSG,
		EPROGMISMATCH_MSG, EPROCUNAVAIL_MSG, ENOLCK_MSG, ENOSYS_MSG, EFTYPE_MSG,
		EAUTH_MSG, ENEEDAUTH_MSG, EPWROFF_MSG, EDEVERR_MSG, EOVERFLOW_MSG,
		EBADEXEC_MSG, EBADARCH_MSG, ESHLIBVERS_MSG, EBADMACHO_MSG, ECANCELED_MSG,
		EIDRM_MSG, ENOMSG_MSG, EILSEQ_MSG, ENOATTR_MSG, EBADMSG_MSG, EMULTIHOP_MSG,
		ENODATA_MSG, ENOLINK_MSG, ENOSR_MSG, ENOSTR_MSG, EPROTO_MSG, ETIME_MSG,
		EOPNOTSUPP_MSG, ENOPOLICY_MSG, ENOTRECOVERABLE_MSG, EOWNERDEAD_MSG,
		EQFULL_MSG};

	if (error > 0 && error < ELAST)
		return (msg_err[error - 1]);
	return (NULL);
}

int	ft_perror(char *error, char *fct)
{
	if (fct)
		dprintf(STDERR_FILENO, "ft_ping: %s: %s\n", fct, error);
	else
		dprintf(STDERR_FILENO, "ft_ping: %s\n", error);
	return (0);
}

int	fatal_error(int error, char *arg, char option)
{
	char		*msg[] = {TRANSMERR_MSG, NOHOST_MSG};
	int			status;
	
	if (error <= ELAST)
		ft_perror(ft_strerror(error), arg);
	else if (error <= NOHOST)
		dprintf(STDERR_FILENO, "%s", msg[error - ELAST - 1]);
	else if (error == BADARG)
		dprintf(STDERR_FILENO, BADARG_MSG, arg);
	else if (error == BADOPT)
	{
		dprintf(STDERR_FILENO, BADOPT_MSG, option);
		print_help();
	}
	else if (error == NOARG)
	{
		dprintf(STDERR_FILENO, BADOPT_MSG, option);
		print_help();
	}
	else if (error == ARGOOR)
		dprintf(STDERR_FILENO, ARGOOR_MSG, arg, 1, LLONG_MAX);
	else
		dprintf(STDERR_FILENO, "ft_ping: Unknown error %d", error);
	clean();
	status = (error >= NOHOST) ? USAGE_ERR : ERROR;
	exit(status);
}
