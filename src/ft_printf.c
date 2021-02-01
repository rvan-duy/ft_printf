/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 01:01:20 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/02 00:21:47 by rvan-duy      ########   odam.nl         */
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

int main()
{
	char *s = ft_strdup("Hello");
	//char *s = NULL;

	printf("ret: %d\n" , printf("(%-3.4s)", s));
	ft_printf("ret: %d\n" , ft_printf("(%-3.4s)", s));
	//printf("(%20.6s)\n", s);
	//ft_printf("(%20.6s)\n", s);
	//printf("(%20.14s)\n", s);
	//ft_printf("(%20.14s)\n", s);
	return 0;
}