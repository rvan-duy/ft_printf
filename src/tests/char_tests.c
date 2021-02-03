/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_tests.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 12:34:48 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/03 14:22:47 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tests.h"

int     pf_tests_char_all()
{
    int i = 0;
    int ret1;
    int ret2;

    while (i <= 255)
    {
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%c) - ", i, i));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%c) - ", i, i));
        if (ret1 != ret2)
        {
            ft_printf("test %d failed!\n", i);
            return (0);
        }
        i++;
    }
    return (1);
}

void    pf_tests_char_random()
{
    char c = 'c';

    printf("Real printf value: %d\n", printf("(%-c)\n", c));
    ft_printf("Your printf value: %d\n", ft_printf("(%-c)\n", c));
    printf("Real printf value: %d\n", printf("(%-9c)\n", c));
    ft_printf("Your printf value: %d\n", ft_printf("(%-9c)\n", c));
    printf("Real printf value: %d\n", printf("(%-0c)\n", c));
    ft_printf("Your printf value: %d\n", ft_printf("(%-0c)\n", c));
    printf("Real printf value: %d\n", printf("(%-1c)\n", c));
    ft_printf("Your printf value: %d\n", ft_printf("(%-1c)\n", c));
    printf("Real printf value: %d\n", printf("(%9c)\n", c));
    ft_printf("Your printf value: %d\n", ft_printf("(%9c)\n", c));
    printf("Real printf value: %d\n", printf("(%-09c)\n", c));
    ft_printf("Your printf value: %d\n", ft_printf("(%-09c)\n", c));
    return ;
}