/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_s_create.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 17:07:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/27 17:06:51 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		pf_string_s_create(t_params *p, va_list args)
{
	char *str;

	str = va_arg(args, char*);
	str = pf_string_expand(str, ' ', p->width, p->flag_minus);
	return (ft_putstr_fd(str, 1));
}
