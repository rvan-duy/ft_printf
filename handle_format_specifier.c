/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_format_specifier.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 11:27:39 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/05 14:34:58 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int         printf_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '.')
        i++;
    return (i);
}

int         read_width(const char *c)
{
    // segfaults if substr returns NULL
    return (ft_atoi(ft_substr(c, 0, printf_strlen(c))));
}

char        read_flag(const char c)
{
    if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
        return (c);
    return (NULL);
}

parameters  make_struct(const char *c, va_list args)
{
    parameters new_struct;

    new_struct.flag = read_flag(*c);
    if (new_struct.flag)
        c++;
    new_struct.width = read_width(c);
    return (new_struct);
}

void        handle_format_specifier(const char *c, va_list args)
{
    parameters params;
    
    c++;
    params = make_struct(c, args);
}