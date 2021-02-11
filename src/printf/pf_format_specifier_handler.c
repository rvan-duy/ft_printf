/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_format_specifier_handler.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 01:21:20 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/11 16:19:25 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static int	pf_format_read(const char *c, t_params *p, va_list args)
{
	char *ptr;
	
	p->width = 1;
	p->precision = -1;
	/*if (pf_specifier_len(c, p))
	{
		p->str = ft_strndup(c, p->len);
		ptr = p->str;
	}
	if (!p->str || !p->len)
		return (-1);*/
	pf_flags_read(c, p);
	pf_width_read(p, args);
	if (p->flag_zero && p->flag_minus)
		p->flag_zero = 0;
	pf_precision_read(p, args);
	pf_specifier_read(p);
	free(ptr);
	return (1);
}

int			pf_format_specifier_handler(const char *c, va_list args, int *len)
{
	t_params	format;
	int 		ret;

	c++;
	ret = pf_format_read(c, &format, args);
	if (ret == 1)
	{
		*len += format.len + 1;
		return (pf_string_create(&format, args));
	}
	return (ret);
}
