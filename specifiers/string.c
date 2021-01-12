/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 18:33:59 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/12 18:39:59 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char    *generate_s_string(parameters input, va_list args)
{
    char *str;
    char *tmp;

    if (!input.width)
        input.width = 1;
    tmp = va_arg(args, char*);
    str = apply_width(tmp, ' ', input);
    if (!str)
        return (NULL);
    return (str);
}