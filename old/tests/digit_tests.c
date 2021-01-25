/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   digit_tests.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 16:52:05 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 17:04:21 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tests.h"

int     pf_tests_digits_random(int max_size)
{
    int i = 0;
    int d;
    int ret1;
    int ret2;

    while (i <= 1000)
    {
        d = rand() % max_size;
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%d) - ", i, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%d) - ", i, d));
        if (ret1 != ret2)
        {
            ft_printf("test %d failed!\n", i);
            return (0);
        }
        i++;
    }
    return (1);
}

int     pf_tests_digits_widths_random()
{
    int i = 0;
    int d;
    int w;
    int ret1;
    int ret2;

    while (i <= 100)
    {
        d = rand();
        w = rand() % 50;
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%*d) - ", i, w, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%*d) - ", i, w, d));
        if (ret1 != ret2)
        {
            ft_printf("test %d failed!\n", i);
            return (0);
        }
        i++;
    }
    return (1);
}
