/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:42:56 by adbenoit          #+#    #+#             */
/*   Updated: 2022/07/01 18:00:11 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

char    *add_flag(char flag, char *dest)
{
    size_t i;

    if (!strchr(FLAGS, flag))
        ft_strerror(ERR_OPTION, NULL, flag);
    i = 0;
    for (; dest[i]; i++)
    {
        if (flag == '4' || flag == '6')
        {
            if (strchr(dest, '4') || strchr(dest, '6'))
                ft_strerror(ERR_OPTION, NULL, flag);
        }
        if (dest[i] == flag && flag != '4' && flag != '6')
            return (dest);
        else if (dest[i] == flag)
            ft_strerror(ERR_OPTION, NULL, flag);
    }
    dest[i] = flag;
    return (dest);        
}

int     parser(char **arg)
{
    char    *host;
    
    host = NULL;
    for (size_t i = 0; arg[i]; i++)
    {
        if (arg[i][0] == '-')
        {
            for (int j = 1; arg[i][j]; j++)
            {
                add_flag(arg[i][j], g_data.flags);
                if (arg[i][j] == 'h')
                    return (0);
            }
        }
        else
            host = arg[i];
    }
    if (!host)
        ft_strerror(ERR_USAGE, NULL, 0);
    g_data.host = strdup(host); 
    if (!g_data.host)
        return (ft_strerror(ENOMEM, NULL, 0));
    return (0);
}
