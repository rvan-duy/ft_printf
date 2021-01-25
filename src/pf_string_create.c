/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_create.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 16:57:36 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/25 22:11:01 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_string_create(t_params *p, va_list args)
{
	char *str;

    str = NULL;
	if (p->specifier == 'c')
		str = NULL; //pf_string_c_create(p, args);
	else if (p->specifier == 'd' || p->specifier == 'i')
		str = pf_string_d_create(p, args);
	else if (p->specifier == 's')
		str = pf_string_s_create(p, args);
	else if (p->specifier == 'u')
		str = pf_string_u_create(p, args);
	else if (p->specifier == 'x' || p->specifier == 'X')
		str = pf_string_x_create(p, args);
	else if (p->specifier == 'p')
		str = pf_string_p_create(p, args);
	else if (p->specifier == '%')
		str = ft_strdup("%");
	if (!str)
		return (pf_error_return(p->specifier));
	return (str);
}
