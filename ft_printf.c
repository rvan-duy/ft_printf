/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 20:21:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/22 16:21:51 by rubenz        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	printline(const char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		if (c[i] == '%')
			return (i);
		write(1, c + i, 1);
		i++;
	}
	return (-1);
}

int	ft_printf(const char *c, ...)
{
    	va_list args;
    	int i;

	va_start(args, c);
    	i = printline(c);
    	if (c[i] == '%')
    	{
        	i++;
		if (c[i] == '%')
			write (1, c + i, 1);
    	}
	return (0);
}

int main()
{
    	//printf("%");
	printf("line%%\n");
    	ft_printf("line%%\n");
    	return 0;
}
