/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 01:01:20 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/05 16:51:18 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *c, ...)
{
	va_list args;
	int		len;
	int 	ret;
	int		fret;

	len = 0;
	ret = 0;
	va_start(args, c);
	while (c[len])
	{
		if (c[len] != '%')
		{
			ret += ft_putchar_fd(c[len], 1);
			len++;
		}
		else
		{
			fret = pf_format_specifier_handler(c + len, args, &len);
			if (fret < 0)
				break;
			ret += fret;
		}
	}
	va_end(args);
	if (fret < 0)
		return (-1);
	return (ret);
}
