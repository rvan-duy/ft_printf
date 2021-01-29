/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_format_specifier_handler.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 01:21:20 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/29 23:28:55 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		PF_PRINT_STRUCT(t_params *p)
{
	printf("-- STRUCT --\n");
	printf("- len: %d\n", p->paramlen);
	printf("- str: %s\n", p->str);
	printf("- flag_minus: %d\n", p->flag_minus);
	printf("- flag_zero: %d\n", p->flag_zero);
	printf("- width: %d\n", p->width);
	printf("- precision: %d\n", p->precision);
	printf("- specifier: %c\n", p->specifier);
	printf("-- END OF STRUCT --\n");
}

static int	pf_format_read(const char *c, t_params *p, va_list args)
{
	p->width = 0;
	p->precision = 0;
	if (pf_specifier_len(c, p))
		p->str = ft_strndup(c, p->paramlen);
	if (!p->str || !p->paramlen)
		return (0);
	pf_flags_read(p);
	pf_width_read(p, args);
	pf_precision_read(p, args);
	pf_specifier_read(p);
	if (!p->width)
		p->width = 1;
	free(p->str - p->paramlen);
	return (1);
}

int			pf_format_specifier_handler(const char *c, va_list args, int *len)
{
	t_params	format;

	c++;
	if (pf_format_read(c, &format, args))
	{
		*len += format.paramlen + 1;
		return (pf_string_create(&format, args));
	}
	return (pf_error_return(format.precision));
}
