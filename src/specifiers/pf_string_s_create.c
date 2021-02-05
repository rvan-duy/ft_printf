/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_s_create.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 17:07:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/05 16:52:53 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_string_s_create(t_params *p, va_list args)
{
	char 	*str;
	char 	*tmp;
	int 	ret;

	tmp = va_arg(args, char*);
	if (tmp && p->precision == -1)
		str = ft_strdup(tmp);
	else if (tmp)
		str = ft_strndup(tmp, p->precision);
	else
		str = ft_strndup("(null)", p->precision);
	str = pf_string_expand(str, ' ', p->width, p->flag_minus);
	ret = ft_putstr_fd(str, 1);
	free(str);
	ret = (ret == 0 && str == NULL) ? -1 : ret; // maak aparte functie hiervoor
	return (ret);
}
