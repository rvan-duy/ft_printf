/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_s_create.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 17:07:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/02 00:22:06 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		pf_string_s_create(t_params *p, va_list args)
{
	char *str;
	char *tmp;

	tmp = va_arg(args, char*);
	if (p->precision == -1)
		str = ft_strdup(tmp);
	else
		str = ft_strndup(tmp, p->precision);
	free(tmp);
	str = pf_string_expand(str, ' ', p->width, p->flag_minus);
	return (ft_putstr_fd(str, 1));
}
