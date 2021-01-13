/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 11:30:31 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/13 16:51:06 by rvan-duy      ########   odam.nl         */
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
void        handle_format_specifier(const char *c, va_list args, lengths *lens);
parameters  make_struct_format(const char *c, va_list args);
char        *generate_string(parameters input, va_list args);
char        *generate_c_string(parameters input, va_list args);
char        *generate_d_string(parameters input, va_list args);
char        *generate_s_string(parameters input, va_list args);
char        *generate_u_string(parameters input, va_list args);
char        *expand_str(char *str, char padder, int range, int flag_minus);
char        find_padder(int flag_zero);

// ILLEGAL -- REMOVE AFTERWARDS
void        print_struct(parameters input);

#endif