/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:31:36 by adbenoit          #+#    #+#             */
/*   Updated: 2022/06/29 17:52:29 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int main(int ac, char **av)
{
    char    *host;

    host = NULL;
    if (ac == 1)
        return (ft_strerror(EX_USAGE, host));
    if (strcmp(av[ac - 1], "localhost") == 0)
        host = strdup("127.0.0.1");
    else
        host = strdup(av[ac - 1]);  
    // if (parse(host))
    //     return (ft_strerror(EX_NOHOST, host));
    
    if (!host)
        return (ft_strerror(ENOMEM, host));
    printf("PING %s (%s): 56 data bytes\n", av[ac - 1], host);
    free(host);
    return (0);
}
