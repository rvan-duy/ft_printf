/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 20:21:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/20 18:53:22 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_printf(const char * c, ...)
{
    va_list args;
    va_start(args, c);

    if (*c == '%')
    {
        int i = va_arg(args, int);
        write(1, i, 2);
    }
    else
    {
        write()
    }
    
}

int main()
{
    printf("asd");
    ft_printf("asd");
    return 0;
}