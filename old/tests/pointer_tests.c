/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointer_tests.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 16:18:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 16:53:35 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tests.h"

void    pf_tests_pointers_run()
{
    int c = 45;
    printf(" return %d\n", printf("(%p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%10p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%10p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%1p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%1p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%0p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%0p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%.0p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%.0p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%.20p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%.20p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%.2p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%.2p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%1.1p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%1.1p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%30.2p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%30.2p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%1.40p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%1.40p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%5.5p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%5.5p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%0.0p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%0.0p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%-p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%-p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%0-p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%0-p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%0p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%0p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%030p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%030p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%030.20p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%030.20p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%030.50p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%030.50p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%0.20p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%0.20p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%30.28p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%30.28p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%01p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%01p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%01.1p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%01.1p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%030.1p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%030.1p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%01.30p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%01.30p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%-30.1p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%-30.1p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%-1.30p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%-1.30p %p %p", &c, NULL, &c));
    printf(" return %d\n", printf("(%030.1p %p %p", &c, NULL, &c));
    ft_printf(" return %d\n", ft_printf("(%030.1p %p %p", &c, NULL, &c));   
}

void    pf_tests_pointers_null_run()
{
    printf(" return %d\n", printf("(%p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%p)", NULL));
    printf(" return %d\n", printf("(%10p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%10p)", NULL));
    printf(" return %d\n", printf("(%1p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%1p)", NULL));
    printf(" return %d\n", printf("(%0p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%0p)", NULL));
    printf(" return %d\n", printf("(%.0p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%.0p)", NULL));
    printf(" return %d\n", printf("(%.20p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%.20p)", NULL));
    printf(" return %d\n", printf("(%.2p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%.2p)", NULL));
    printf(" return %d\n", printf("(%1.1p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%1.1p)", NULL));
    printf(" return %d\n", printf("(%30.2p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%30.2p)", NULL));
    printf(" return %d\n", printf("(%1.40p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%1.40p)", NULL));
    printf(" return %d\n", printf("(%5.5p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%5.5p)", NULL));
    printf(" return %d\n", printf("(%0.0p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%0.0p)", NULL));
    printf(" return %d\n", printf("(%-p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%-p)", NULL));
    printf(" return %d\n", printf("(%0-p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%0-p)", NULL));
    printf(" return %d\n", printf("(%0p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%0p)", NULL));
    printf(" return %d\n", printf("(%030p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%030p)", NULL));
    printf(" return %d\n", printf("(%030.20p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%030.20p)", NULL));
    printf(" return %d\n", printf("(%030.50p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%030.50p)", NULL));
    printf(" return %d\n", printf("(%0.20p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%0.20p)", NULL));
    printf(" return %d\n", printf("(%30.28p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%30.28p)", NULL));
    printf(" return %d\n", printf("(%01p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%01p)", NULL));
    printf(" return %d\n", printf("(%01.1p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%01.1p)", NULL));
    printf(" return %d\n", printf("(%030.1p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%030.1p)", NULL));
    printf(" return %d\n", printf("(%01.30p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%01.30p)", NULL));
    printf(" return %d\n", printf("(%-30.1p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%-30.1p)", NULL));
    printf(" return %d\n", printf("(%-1.30p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%-1.30p)", NULL));
    printf(" return %d\n", printf("(%030.1p)", NULL));
    ft_printf(" return %d\n", ft_printf("(%030.1p)", NULL));
}

int     pf_tests_pointers_random()
{
    int i = 0;
    int ret1;
    int ret2;
    int d;
    int p;
    int w;

    while (i <= 1000)
    {
        d = rand() % 100;
        p = rand() % 100;
        w = rand() % 100;
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%*.*p) - ", i, w, p, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%*.*p) - ", i, w, p, d));
        if (ret1 != ret2)
        {
            ft_printf("test %d failed!\n", i);
            return (0);
        }
        i++;
    }
    return (1);
}
