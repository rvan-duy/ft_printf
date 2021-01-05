/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 20:21:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/05 14:32:46 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *c, ...)
{
    va_list args;
    int i;

    i = 0;
	va_start(args, c);
    while (*c)
    {
        if (*c != '%')
            ft_putchar_fd(*c, 1);
        else
            handle_format_specifier(c, args);
        c++;
    }
    va_end(args);
	return (1);
}

int main()
{
    //printf("%d", '0');
    //printf("%05d\n", 3);
    ft_printf("hoi% 456d\n", 3);
    //ft_printf("hoi% d\n", 3);
    return 0;
}
