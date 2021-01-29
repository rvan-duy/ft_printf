/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 01:01:20 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/29 13:20:36 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *c, ...)
{
	va_list args;
	int		len;

	len = 0;
	va_start(args, c);
	while (c[len])
	{
		if (c[len] != '%')
		{
			ft_putchar_fd(c[len], 1);
			len++;
		}
		else
			len += pf_format_specifier_handler(c + len, args);
	}
	va_end(args);
	return (len);
}

int main()
{
	char c = 'd';

	printf("%d - " , printf("(%10c)\n", c));
	//ft_printf("(%10c)\n", c);



	return 0;
}