/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_format_specifier.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 17:19:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/06 17:27:58 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        handle_format_specifier(const char *c, va_list args)
{
    parameters params;
    
    c++;
    params = make_struct_format(c, args);
    // check if it stops at the specifier, it shouldn't free the whole string. Unless I only give it the string with specifiers.
}