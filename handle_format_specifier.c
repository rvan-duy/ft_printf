/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_format_specifier.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 17:19:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/11 17:23:06 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_format_specifier(const char *c, va_list args)
{
    parameters params;

    c++;
    params = make_struct_format(c, args);
    
    
    return (params.len + 1);
}