/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_format_specifier.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 17:19:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/12 00:05:23 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_format_specifier(const char *c, va_list args)
{
    parameters  params;
    char        *str;

    c++;
    params = make_struct_format(c, args);
    str = generate_string(params, args); // if str = NULL?
    ft_putstr_fd(str, 1);
    return (params.len + 1);
}
