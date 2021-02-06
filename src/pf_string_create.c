/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_create.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 16:57:36 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/06 17:59:46 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_string_create(t_params *p, va_list args)
{
	if (p->specifier == 'c')
		return (pf_string_c_create(p, args));
	if (p->specifier == 'd' || p->specifier == 'i')
		return (pf_string_d_create(p, args));
	if (p->specifier == 's')
		return (pf_string_s_create(p, args));
	if (p->specifier == 'u')
		return (pf_string_u_create(p, args));
	if (p->specifier == 'x' || p->specifier == 'X')
		return (pf_string_x_create(p, args));
	if (p->specifier == 'p')
		return (pf_string_p_create(p, args));
	if (p->specifier == '%')
		return (pf_string_percentage_create(p));
	return (0);
}
