/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 01:01:20 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/02 16:56:11 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *c, ...)
{
	va_list args;
	int		len;
	int 	ret;

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
			ret += pf_format_specifier_handler(c + len, args, &len);
	}
	va_end(args);
	return (ret);
}

/*
int main()
{
	printf("return value: (%d) <---- Real Printf\n", printf("(%0.*d) - ", 0, 10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("(%0.*d) - ", 0, 10));
	printf("return value: (%d) <---- Real Printf\n", printf("(%0.*d) - ", 0, -10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("(%0.*d) - ", 0, -10));
	return 0;
}*/