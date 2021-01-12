/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   digits.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 10:49:38 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/12 13:29:37 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char    *generate_d_string(parameters input, va_list args)
{
    char    *tmp;
    char    *str;
    char    padder;

    if (input.flag_zero)
        padder = '0';
    else
        padder = ' ';
    if (!input.width)
        input.width = 1;
    tmp = ft_itoa(va_arg(args, int));
    if (!tmp)
        return (NULL);
    str = apply_width(tmp, padder, input);
    if (!str)
        return (NULL);
    return (str);
}
