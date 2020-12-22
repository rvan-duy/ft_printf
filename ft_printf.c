/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 20:21:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/22 18:11:31 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printf(const char *c, ...)
{
    va_list args;
    int i;
    int ch;

    i = 0;
	va_start(args, c);
    while (c[i])
    {
        if (c[i] == '%')
        {
            i++;
            if (c[i] == '%')
                write(1, c, 1);
            else if (c[i] == 'c' || c[i] == 'd' || c[i] == 'i')
            {
                ch = va_arg(args, int);
                printf("%c", ch);
            }
        }
        else
            write (1, c + i, 1);
        i++;
    }
	return (1);
}

int main()
{
	printf("%c\n", 's');
    ft_printf("%c\n", 's');
    return 0;
}
