/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 11:30:31 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/06 17:20:21 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct
{
    char    *str;
    char    flag;
    int     width;
    int     precision;
    char    specifier;   
} parameters;

void        handle_format_specifier(const char *c, va_list args);
parameters  make_struct_format(const char *c, va_list args);

#endif