/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 22:09:43 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/12 00:21:17 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char    *make_c_string(parameters input, va_list args)
{
    char    *str;
    int     i;

    i = 0;
    str = ft_calloc(input.width + 1, sizeof(char));
    if (!str)
        return (NULL);
    if (!input.flag_minus)
    {
        ft_memset(str, ' ', input.width - 1);
        str[input.width - 1] = va_arg(args, int);
    }
    else
    {
        str[i] = va_arg(args, int);
        i++;
        while (i < input.width)
        {
            str[i] = ' ';
            i++;
        }
    }
    return (str);
}

char    *generate_c_string(parameters input, va_list args)
{
    char    *str;

    if (!input.width)
        input.width = 1;
    str = make_c_string(input, args);
    if (!str)
        return (NULL);
    return (str);
}