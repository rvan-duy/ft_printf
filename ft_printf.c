/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 20:21:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/22 17:58:41 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printf(const char *c, ...)
{
    va_list args;
    int i;

    i = 0;
	va_start(args, c);
    while (c[i])
    {
        if (c[i] == '%')
        {
            i++;
            if (c[i] == '%')
                write(1, c + i, 1);
        }
        else
        {
            write (1, c + i, 1);
            i++;
        }
    }
	return (1);
}

int main()
{
	printf("line%%\n");
    ft_printf("line%%\n");
    return 0;
}
