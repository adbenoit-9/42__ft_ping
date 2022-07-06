#include "ft_ping.h"

int ft_strerror(int error, char *host, char option)
{
    if (error == ERR_USAGE && !host)
        printf("ft_ping: usage error: Destination address required\n");
    else if (error == ERR_USAGE)
        printf("ft_ping: %s: Name or service not known\n", host);
    else if (error == ERR_AF)
    {
        printf("ft_ping: %s: Address family for hostname not supported\n", host);
        error = 2;
    }
    else if (error == ERR_OPTION && (option == '4' || option == '6'))
        printf("ping: only one -4 or -6 option may be specified\n");
    else if (error == ERR_OPTION)
    {
        printf("ft_ping: invalid option -- %c\n", option);
        print_help();
    }
    else if (error == ENOMEM)
        printf("error: out of memory\n");
    clean();
    exit(error);
}
