#include "ft_ping.h"

int ft_perror(int error, char *arg, char option)
{
    if (error == ERR_USAGE && !arg)
        dprintf(STDERR_FILENO, "ft_ping: usage error: Destination address required\n");
    else if (error == ERR_USAGE)
        dprintf(STDERR_FILENO, "ft_ping: %s: Name or service not known\n", arg);
    else if (error == ERR_AF)
    {
        dprintf(STDERR_FILENO, "ft_ping: %s: Address family for hostname not supported\n", arg);
        error = 2;
    }
    else if (error == ERR_OPTION && (option == '4' || option == '6'))
        dprintf(STDERR_FILENO, "ping: only one -4 or -6 option may be specified\n");
    else if (error == ERR_OPTION)
    {
        dprintf(STDERR_FILENO, "ft_ping: invalid option -- %c\n", option);
        print_help();
    }
    else if (error == ENOMEM)
        dprintf(STDERR_FILENO, "ft_ping: out of memory\n");
    else if (error == ERR_SOCK)
        dprintf(STDERR_FILENO, "ft_ping: socket error\n");
    else if (error == ERR_ARG)
    {
        dprintf(STDERR_FILENO, "ft_ping: invalid agument: '%s'", arg);
        if (isnumber(arg))
            dprintf(STDERR_FILENO, ": out of range: 1 <= value <= 9223372036854775807\n");
        else
            dprintf(STDERR_FILENO, "\n");
        error = 1;
    }
    clean();
    exit(error);
}
