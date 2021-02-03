/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   digit_tests.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 16:52:05 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/03 12:56:54 by rvan-duy      ########   odam.nl         */
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

static int  pf_tests_digits_minus_flag()
{
    int i = 0;
    int d;
    int w;
    int ret1;
    int ret2;

    while (i <= 10)
    {
        d = rand();
        w = rand() % 50;
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%-*d) - ", i, w, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%-*d) - ", i, w, d));
        if (ret1 != ret2)
        {
            ft_printf("test %d failed!\n", i);
            return (0);
        }
        i++;
    }
    return (1);
}

static int  pf_tests_digits_zero_flag()
{
    int i = 0;
    int d;
    int w;
    int ret1;
    int ret2;

    while (i <= 10)
    {
        d = rand();
        w = rand() % 50;
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%0*d) - ", i, w, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%0*d) - ", i, w, d));
        if (ret1 != ret2)
        {
            ft_printf("test %d failed!\n", i);
            return (0);
        }
        i++;
    }
    return (1);
}

static int  pf_tests_digits_minus_and_zero_flag()
{
    int i = 0;
    int d;
    int w;
    int ret1;
    int ret2;

    while (i <= 10)
    {
        d = rand();
        w = rand() % 50;
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%0-*d) - ", i, w, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%0-*d) - ", i, w, d));
        if (ret1 != ret2)
        {
            ft_printf("test %d failed!\n", i);
            return (0);
        }
        i++;
    }
    return (1);
}

void         pf_tests_digits_random_flags()
{
    printf("Testing with minus flag:\n");
    pf_tests_digits_minus_flag();
    printf("Testing with zero flag:\n");
    pf_tests_digits_zero_flag();
    printf("Testing with both flags:\n");
    pf_tests_digits_minus_and_zero_flag();
    return ;
}

void        pf_tests_digits_0flag_precision()
{
    int i = 1;
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%0.*d) - ", i, 10, 10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%0.*d) - ", i++, 10, 10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%0.*d) - ", i, 10, 1));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%0.*d) - ", i++, 10, 1));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%0.*d) - ", i, 1, 10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%0.*d) - ", i++, 1, 10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%-.*d) - ", i, 10, 10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%-.*d) - ", i++, 10, 10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%-0.*d) - ", i, 1, 10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%-0.*d) - ", i++, 1, 10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%-0.*d) - ", i, 10, 10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%-0.*d) - ", i++, 10, 10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%-0.*d) - ", i, 1, 10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%-0.*d) - ", i++, 1, 10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%-0.*d) - ", i, 0, 10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%-0.*d) - ", i++, 0, 10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%0.*d) - ", i, 0, 10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%0.*d) - ", i++, 0, 10));
}

void    pf_tests_digits_negatives()
{
    int i = 1;
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%0.*d) - ", i, 10, -10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%0.*d) - ", i++, 10, -10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%0.*d) - ", i, 10, -1));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%0.*d) - ", i++, 10, -1));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%0.*d) - ", i, 1, -10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%0.*d) - ", i++, 1, -10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%-.*d) - ", i, 10, -10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%-.*d) - ", i++, 10, -10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%-0.*d) - ", i, 1, -10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%-0.*d) - ", i++, 1, -10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%-0.*d) - ", i, 10, -10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%-0.*d) - ", i++, 10, -10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%-0.*d) - ", i, 1, -10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%-0.*d) - ", i++, 1, -10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%-0.*d) - ", i, 0, -10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%-0.*d) - ", i++, 0, -10));
    printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%0.*d) - ", i, 0, -10));
    ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%0.*d) - ", i++, 0, -10));
}

void    pf_tests_digits_over_max()
{
    int w = 30;
    int p = 20;
    unsigned int u = 3000000000;
    printf("- return value: %d\n", printf("%d ", u));
    ft_printf("- return value: %d\n", ft_printf("%d ", u));
    printf("- return value: %d\n", printf("%d ", u));
    ft_printf("- return value: %d\n", ft_printf("%d ", u));
    printf("- return value: %d\n", printf("%*d ", w, u));
    ft_printf("- return value: %d\n", ft_printf("%*d ", w, u));
    printf("- return value: %d\n", printf("%*.*d ", w, p, u));
    ft_printf("- return value: %d\n", ft_printf("%*.*d ", w, p, u));
    printf("- return value: %d\n", printf("%-*.*d ", w, p, u));
    ft_printf("- return value: %d\n", ft_printf("%-*.*d ", w, p, u));
    printf("- return value: %d\n", printf("%*d ", w, -10));
    ft_printf("- return value: %d\n", ft_printf("%*d ", w, -10));
    printf("- return value: %d\n", printf("%0*d ", w, -10));
    ft_printf("- return value: %d\n", ft_printf("%0*d ", w, -10));
    printf("- return value: %d\n", printf("%0*.*d ", w, p, u));
    ft_printf("- return value: %d\n", ft_printf("%0*.*d ", w, p, u));
    printf("- return value: %d\n", printf("%0-*.*d ", w, p, u));
    ft_printf("- return value: %d\n", ft_printf("%0-*.*d ", w, p, u));
    printf("- return value: %d\n", printf("%0-*.*d ", w, 2, u));
    ft_printf("- return value: %d\n", ft_printf("%0-*.*d ", w, 2, u));
    return ;
}