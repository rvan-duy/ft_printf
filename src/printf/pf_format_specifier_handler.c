/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_format_specifier_handler.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 01:21:20 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/12 14:30:38 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	pf_specifier_strlen(const char *s, char specifier)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == specifier)
			return (i);
		i++;
	}
	return (0);
}

static int	pf_format_read(const char *c, t_params *p, va_list args)
{
	p->width = 1;
	p->precision = -1;
	p->str = (char *)c;
	pf_flags_read(p);
	pf_width_read(p, args);
	pf_precision_read(p, args);
	if (p->flag_minus && p->flag_zero)
		p->flag_zero = 0;
	if (pf_specifier_read(p))
		return (1);
	return (0);
}

int	pf_format_specifier_handler(const char *c, va_list args, int *len)
{
	t_params	format;

	c++;
	if (pf_format_read(c, &format, args))
	{
		*len += pf_specifier_strlen(c, format.specifier) + 2;
		return (pf_string_create(&format, args));
	}
	*len += 1;
	return (0);
}
