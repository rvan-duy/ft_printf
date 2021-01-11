/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_format_specifier.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 17:19:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/08 16:45:16 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int is_specifier(char c)
{
    char specifiers[] = { 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%' };
    if (ft_strchr(specifiers, c))
        return (1);
    return (0);
}

int find_specifier_len(const char *c)
{
    int i;

    i = 1;
    while (!is_specifier(c[i]))
        i++;
    return (i);
}

int handle_format_specifier(const char *c, va_list args)
{
    parameters params;
    
    c++;
    params.len = find_specifier_len(c);
    // strndup
    params = make_struct_format(c, args);
    // check if it stops at the specifier, it shouldn't free the whole string. Unless I only give it the string with specifiers.
}