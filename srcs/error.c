#include "ft_ping.h"

int ft_strerror(int error, char *host)
{
    if (error == EX_USAGE)
        printf("usage: ping host\n");
    else if (error == EX_NOHOST)
        printf("ft_ping: cannot resolve %s: Unknown host\n", host);
    else if (error == ENOMEM)
        printf("error: out of memory");
    free(host);
    return (error);
}
