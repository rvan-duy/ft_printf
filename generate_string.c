/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_string.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 21:38:15 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/12 13:28:37 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *generate_string(parameters input, va_list args)
{
    char *str;

    if (input.specifier == 'c')
        str = generate_c_string(input, args);
    if (input.specifier == 'd' || input.specifier == 'i')
        str = generate_d_string(input, args);
    if (!str)
        return (NULL);
    return (str);
}