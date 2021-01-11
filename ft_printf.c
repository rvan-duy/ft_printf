/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 20:21:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/11 23:05:24 by rvan-duy      ########   odam.nl         */
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

    //printf("%+ d\n", 3);
    //printf("%05d\n", 3);
    //ft_printf("hoi%-*.*casd\n", 3, 4, 'h');
    //ft_printf("hoi% d\n", 3);
    ft_printf("%20c\n", 'a');
    //printf("(%c)\n", 'c');
    //printf("(%-c)\n", 'c');
    //printf("(%5c)\n", 'c');
    //printf("(%-5c)\n", 'c');
    
    
    return 0;
}
