/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 20:21:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/14 17:29:52 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putchar_len(char c, lengths *lens)
{
    write(1, &c, 1);
    lens->specifier++;
    lens->str++;
}

int     ft_printf(const char *c, ...)
{
    va_list args;
    lengths lens;

    lens.str = 0;
	va_start(args, c);
    while (*c)
    {
        lens.specifier = 0;
        if (*c != '%')
            ft_putchar_len(*c, &lens);
        else
            handle_format_specifier(c, args, &lens);
        c = c + lens.specifier;
    }
    va_end(args);
	return (lens.str);
}

/* OLD MAIN */
int main()
{
    printf("return value: (%d)\n", printf("test1: (%5.3d) - ", 1));
    ft_printf("return value: (%d)\n", ft_printf("test1: (%5.3d) - ", 1));
    printf("return value: (%d)\n", printf("test1: (%-20.10X) - ", 4545));
    ft_printf("return value: (%d)\n", ft_printf("test1: (%-20.10X) - ", 4545));
    printf("return value: (%d)\n", printf("test1: (%-20.10x) - ", 4545));
    ft_printf("return value: (%d)\n", ft_printf("test1: (%-20.10x) - ", 4545));
    //printf("(%*d)\n", -5, 3);
    //printf("(%+5d)\n", 3);
    //ft_printf("(%-4c)\n", 'g');
    //printf("%+ d\n", 3);
    //printf("%05d\n", 3);
    //ft_printf("hoi%-*.*casd\n", 3, 4, 'h');
    //ft_printf("hoi% d\n", 3);
    //printf("return value: (%d)\n", printf("test1: (%d) - ", 23));
    //ft_printf("return value: (%d)\n", ft_printf("test1: (%d) - ", 23));
    //printf("return value: (%d)\n", printf("test2: (hoi%-*.*dasd) - ", 3, 4, 'h'));
    //ft_printf("return value: (%d)\n", ft_printf("test2: (hoi%-*.*dasd) - ", 3, 4, 'h'));
    //printf("return value: (%d)\n", printf("test1: (%-05x) - ", 15));
    //ft_printf("return value: (%d)\n", ft_printf("test1: (%d) - ", 23));
    //printf("return value: (%d)\n", printf("test2: (%-05X) - ", 15));
    //ft_printf("return value: (%d)\n", ft_printf("test2: (hoi%-*.*dasd) - ", 3, 4, 'h'));
    /*printf("(%-d)\n", 23);
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
    ft_printf("(%060d)\n", 23);
    //printf("%2.2f\n", 3333.3333);
    /*printf("(%5.10d)\n", 23);
    printf("(%10.5d)\n", 23);
    printf("(%5.10d)\n", 23);
    printf("(%10.5d)\n", 23);
    //ft_printf("%%\n");
    //printf("(%10c)\n", 'h');
    //ft_printf("(%10c)\n", 'h');
    //printf("(%-10c)\n", 'h');
    //ft_printf("(%-10c)\n", 'h');
    //unsigned int j = -1;
    //ft_printf("%020u\n", j);
    //printf("%020u\n", j);
    //ft_printf("%d\n", ft_printf("%d%d%d9865865%c\n", 10, 30, 1000, 'd'));
    //printf("%d\n", printf("%d%d%d9865865%c\n", 10, 30, 1000, 'd'));
    //ft_printf("(%10.5d)\n", 11);
    //printf("(%10.5d)\n", 11);
    //ft_printf("(%-10.5d)\n", 11);*/

    return 0;
}