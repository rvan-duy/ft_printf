/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 11:30:31 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/11 13:25:26 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
// ILLEGAL -- REMOVE AFTERWARDS
# include <stdio.h>

typedef struct
{
    int     len;
    char    *str;
    char    *flags;
    int     width;
    int     precision;
    char    specifier;   
} parameters;

int         handle_format_specifier(const char *c, va_list args);
parameters  make_struct_format(const char *c, va_list args);

// ILLEGAL -- REMOVE AFTERWARDS
void        print_struct(parameters input);

#endif