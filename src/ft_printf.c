/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 01:01:20 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/26 11:35:47 by rvan-duy      ########   odam.nl         */
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
	char c = '\0';

	printf("%10c\n", c);
	// write(1, &c, 1);
	// write(1, "\n", 1);
	ft_printf("%10c\n", c);



	return 0;
}