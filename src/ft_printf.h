/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 00:48:30 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/01 23:45:38 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>

# include <stdio.h>

# define SPECIFIERS "cspdiuxX%"
# define WIDTH 'w'
# define PRECISION 'p'

typedef struct		s_params {
	int				paramlen;
	char			*str;
	int				flag_minus;
	int				flag_zero;
	int				width;
	int				precision;
	char			specifier;
}					t_params;

void				PF_PRINT_STRUCT(t_params *p); // delete at the end

/*
** Some usefull comment
*/

int					ft_printf(const char *c, ...);
int					pf_format_specifier_handler(const char *c, va_list args, int *ret);
int					pf_specifier_len(const char *c, t_params *p);
void				pf_flags_read(t_params *p);
void				pf_width_read(t_params *p, va_list args);
void				pf_precision_read(t_params *p, va_list args);
void				pf_specifier_read(t_params *p);
char				*pf_strjoin(char const *s1, char *s2);

int					pf_string_create(t_params *p, va_list args);
char				pf_padder_find(int flag_zero);
int					pf_string_c_create(t_params *p, va_list args);
int					pf_string_s_create(t_params *p, va_list args);
int					pf_string_d_create(t_params *p, va_list args);
int					pf_string_x_create(t_params *p, va_list args);
int					pf_string_u_create(t_params *p, va_list args);
int					pf_string_p_create(t_params *p, va_list args);
char				*pf_string_expand(char *str, char padder, int range, int flag_minus);
int					pf_error_return(t_params *p);


#endif
