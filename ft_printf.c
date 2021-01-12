/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 20:21:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/12 13:48:01 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *c, ...)
{
    va_list args;
    int len;
    
	va_start(args, c);
    while (*c)
    {
        len = 0;
        if (*c != '%')
        {
            ft_putchar_fd(*c, 1);
            len++;
        }
        else
        {
            len = handle_format_specifier(c, args);
            if (!len)
                return (0);
        }
        c = c + len;
    }
    va_end(args);
	return (1);
}

int main()
{
    //printf("(%*d)\n", -5, 3);
    //printf("(%+5d)\n", 3);
    //ft_printf("(%-4c)\n", 'g');
    //printf("%+ d\n", 3);
    //printf("%05d\n", 3);
    //ft_printf("hoi%-*.*casd\n", 3, 4, 'h');
    //ft_printf("hoi% d\n", 3);
    /*printf("(%d)\n", 23);
    ft_printf("(%d)\n", 23);
    printf("(%-d)\n", 23);
    ft_printf("(%-d)\n", 23);
    printf("(%5d)\n", 23);
    ft_printf("(%5d)\n", 23);
    printf("(%-5d)\n", 23);
    ft_printf("(%-5d)\n", 23);
    printf("(%05d)\n", 23);
    ft_printf("(%05d)\n", 23);
    printf("(%-05d)\n", 23);
    ft_printf("(%-05d)\n", 23);
    printf("(%060d)\n", 23);
    ft_printf("(%060d)\n", 23);*/
    //printf("%2.2f\n", 3333.3333);
    /*printf("(%5.10d)\n", 23);
    printf("(%10.5d)\n", 23);
    printf("(%5.10d)\n", 23);
    printf("(%10.5d)\n", 23);*/
    ft_printf("%%\n");
    

    return 0;
}
