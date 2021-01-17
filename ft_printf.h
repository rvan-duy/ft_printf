/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 11:30:31 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 12:25:57 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Remember to make local functions static

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
// ILLEGAL -- REMOVE AFTERWARDS
# include <stdio.h>

# define HEXADECIMALS_UPPER "0123456789ABCDEF"
# define HEXADECIMALS_LOWER "0123456789abcdef"

typedef struct {
    int     str;
    int     specifier;
} lengths;

typedef struct
{
    int     len;
    char    *str;
    int     flag_minus;
    int     flag_zero;
    int     width;
    int     precision;
    char    specifier;
} parameters;

int         ft_printf(const char *c, ...);
void        pf_format_specifier_handler(const char *c, va_list args, lengths *lens);
parameters  pf_struct_format_create(const char *c, va_list args);
char        *pf_string_create(parameters input, va_list args);
char        *pf_string_c_create(parameters input, va_list args);
char        *pf_string_d_create(parameters input, va_list args);
char        *pf_string_s_create(parameters input, va_list args);
char        *pf_string_u_create(parameters input, va_list args);
char        *pf_string_x_create(parameters input, va_list args);
char        *pf_string_p_create(parameters input, va_list args);
char        *pf_string_expand(char *str, char padder, int range, int flag_minus);
char        pf_padder_find(int flag_zero);

// ILLEGAL -- REMOVE AFTERWARDS
void        print_struct(parameters input);

#endif