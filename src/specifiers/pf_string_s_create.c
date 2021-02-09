/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_s_create.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 17:07:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/09 12:11:48 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		pf_string_s_create(t_params *p, va_list args)
{
	char	*str;
	char	*tmp;
	int		ret;

	tmp = va_arg(args, char*);
	if (tmp && p->precision == -1)
		str = ft_strdup(tmp);
	else if (tmp)
		str = ft_strndup(tmp, p->precision);
	else
	{
		if (p->precision < 0)
			p->precision = 6;
		str = ft_strndup("(null)", p->precision);
	}
	str = pf_string_expand(str, ' ', p->width, p->flag_minus);
	ret = ft_putstr_fd(str, 1);
	free(str);
	return (pf_ret_return(ret, str));
}
