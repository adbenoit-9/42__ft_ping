/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:51:23 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/13 17:56:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*
** -- Error codes --
*/
# define BADAF 5
# define BADNAME 8
# define TRANSMERR ELAST + 1
# define NOHOST ELAST + 2
# define BADARG ELAST + 3
# define BADOPT ELAST + 4
# define NOARG ELAST + 5
# define ARGOOR ELAST + 6


/*
** -- Error messages --
*/
# define EPERM_MSG "Operation not permitted"
# define ENOENT_MSG "No such file or directory"
# define ESRCH_MSG "No such process"
# define EINTR_MSG "Interrupted system call"
# define BADAF_MSG "Address family for hostname not supported"
# define ENXIO_MSG "Device not configured"
# define E2BIG_MSG "Argument list too long"
# define NONAME_MSG "Name or service not known"
# define EBADF_MSG "Bad file descriptor"
# define ECHILD_MSG "No child processes"
# define EDEADLK_MSG "Resource deadlock avoided"
# define ENOMEM_MSG "Cannot allocate memory"
# define EACCES_MSG "Permission denied"
# define EFAULT_MSG "Bad address"
# define EBUSY_MSG "Device / Resource busy"
# define EEXIST_MSG "File exists"
# define EXDEV_MSG "Cross-device link"
# define ENODEV_MSG "Operation not supported by device"
# define ENOTDIR_MSG "Not a directory"
# define EISDIR_MSG "Is a directory"
# define EINVAL_MSG "Invalid argument"
# define ENFILE_MSG "Too many open files in system"
# define EMFILE_MSG "Too many open files"
# define ENOTTY_MSG "Inappropriate ioctl for device"
# define ETXTBSY_MSG "Text file busy"
# define EFBIG_MSG "File too large"
# define ENOSPC_MSG "No space left on device"
# define ESPIPE_MSG "Illegal seek"
# define EROFS_MSG "Read-only file system"
# define EMLINK_MSG "Too many links"
# define EPIPE_MSG "Broken pipe"
# define EDOM_MSG "Numerical argument out of domain"
# define ERANGE_MSG "Result too large"
# define EAGAIN_MSG "Resource temporarily unavailable"
# define EWOULDBLOCK_MSG "Operation would block"
# define EINPROGRESS_MSG "Operation now in progress"
# define EALREADY_MSG "Operation already in progress"
# define ENOTSOCK_MSG "Socket operation on non-socket"
# define EDESTADDRREQ_MSG "Destination address required"
# define EMSGSIZE_MSG "Message too long"
# define EPROTOTYPE_MSG "Protocol wrong type for socket"
# define ENOPROTOOPT_MSG "Protocol not available"
# define EPROTONOSUPPORT_MSG "Protocol not supported"
# define ESOCKTNOSUPPORT_MSG "Socket type not supported"
# define ENOTSUP_MSG "Operation not supported"
# define EPFNOSUPPORT_MSG "Protocol family not supported"
# define EAFNOSUPPORT_MSG "Address family not supported by protocol family"
# define EADDRINUSE_MSG "Address already in use"
# define EADDRNOTAVAIL_MSG "Can't assign requested address"
# define ENETDOWN_MSG "Network is down"
# define ENETUNREACH_MSG "Network is unreachable"
# define ENETRESET_MSG "Network dropped connection on reset"
# define ECONNABORTED_MSG "Software caused connection abort"
# define ECONNRESET_MSG "Connection reset by peer"
# define ENOBUFS_MSG "No buffer space available"
# define EISCONN_MSG "Socket is already connected"
# define ENOTCONN_MSG "Socket is not connected"
# define ESHUTDOWN_MSG "Can't send after socket shutdown"
# define ETOOMANYREFS_MSG "Too many references: can't splice"
# define ETIMEDOUT_MSG "Operation timed out"
# define ECONNREFUSED_MSG "Connection refused"
# define ELOOP_MSG "Too many levels of symbolic links"
# define ENAMETOOLONG_MSG "File name too long"
# define EHOSTDOWN_MSG "Host is down"
# define EHOSTUNREACH_MSG "No route to host"
# define ENOTEMPTY_MSG "Directory not empty"
# define EPROCLIM_MSG "Too many processes"
# define EUSERS_MSG "Too many users"
# define EDQUOT_MSG "Disc quota exceeded"
# define ESTALE_MSG "Stale NFS file handle"
# define EREMOTE_MSG "Too many levels of remote in path"
# define EBADRPC_MSG "RPC struct is bad"
# define ERPCMISMATCH_MSG "RPC version wrong"
# define EPROGUNAVAIL_MSG "RPC prog. not avail"
# define EPROGMISMATCH_MSG "Program version wrong"
# define EPROCUNAVAIL_MSG "Bad procedure for program"
# define ENOLCK_MSG "No locks available"
# define ENOSYS_MSG "Function not implemented"
# define EFTYPE_MSG "Inappropriate file type or format"
# define EAUTH_MSG "Authentication error"
# define ENEEDAUTH_MSG "Need authenticator"
# define EPWROFF_MSG "Device power is off"
# define EDEVERR_MSG "Device error, e.g. paper out"
# define EOVERFLOW_MSG "Value too large to be stored in data type"
# define EBADEXEC_MSG "Bad executable"
# define EBADARCH_MSG "Bad CPU type in executable"
# define ESHLIBVERS_MSG "Shared library version mismatch"
# define EBADMACHO_MSG "Malformed Macho file"
# define ECANCELED_MSG "Operation canceled"
# define EIDRM_MSG "Identifier removed"
# define ENOMSG_MSG "No message of desired type"
# define EILSEQ_MSG "Illegal byte sequence"
# define ENOATTR_MSG "Attribute not found"
# define EBADMSG_MSG "Bad message"
# define EMULTIHOP_MSG "Reserved"
# define ENODATA_MSG "No message available on STREAM"
# define ENOLINK_MSG "Reserved"
# define ENOSR_MSG "No STREAM resources"
# define ENOSTR_MSG "Not a STREAM"
# define EPROTO_MSG "Protocol error"
# define ETIME_MSG "STREAM ioctl timeout"
# define EOPNOTSUPP_MSG "Operation not supported on socket"
# define ENOPOLICY_MSG "No such policy registered"
# define ENOTRECOVERABLE_MSG "State not recoverable"
# define EOWNERDEAD_MSG "Previous owner died"
# define EQFULL_MSG "Interface output queue is full"

# define TRANSMERR_MSG "ft_ping: transmission failed\n"
# define NOHOST_MSG "ft_ping: usage error: Destination address required\n"
# define BADARG_MSG  "ft_ping: invalid agument: '%s'\n"
# define BADOPT_MSG "ft_ping: invalid option -- '%c'\n"
# define NOARG_MSG "ft_ping: option requires an argument -- '%c'\n"
# define ARGOOR_MSG  "ft_ping: invalid agument: '%s': out of range: %d <= value <= %ld\n"

#endif
