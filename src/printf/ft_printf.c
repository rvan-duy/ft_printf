/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 01:01:20 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/12 14:20:42 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	pf_string_looper(const char *c, va_list args)
{
	int		len;
	int		ret;
	int		fret;

	len = 0;
	ret = 0;
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
				break ;
			ret += fret;
		}
	}
	if (fret < 0)
		return (-1);
	return (ret);
}

int	ft_printf(const char *c, ...)
{
	va_list	args;
	int		ret;

	va_start(args, c);
	ret = pf_string_looper(c, args);
	va_end(args);
	return (ret);
}
