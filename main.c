/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 16:48:18 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/14 20:41:36 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void    main()
{
    int sleeptime = 1;
    int i;
    int d;
    int p;
    int w;
    int ret1;
    int ret2;

    i = 1;
    printf("Starting tests with small digits...\n");
    sleep(sleeptime);
    while (i <= 100)
    {
        d = rand() % 1000;
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%d) - ", i, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%d) - ", i, d));
        if (ret1 != ret2)
        {
            ft_printf("There is a difference in the return value!\n");
            return ;
        }
        i++;
    }
    ft_printf("You succesfully passed all small digit tests!\n");
    sleep(sleeptime);
    ft_printf("Starting tests with big digits...\n");
    i = 1;
    sleep(sleeptime);
    while (i <= 100)
    {
        d = rand();
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%d) - ", i, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%d) - ", i, d));
        if (ret1 != ret2)
        {
            ft_printf("There is a difference in the return value!\n");
            return ;
        }
        i++;
    }
    ft_printf("You succesfully passed all big digit tests!\n");
    sleep(sleeptime);
    ft_printf("Starting tests with digits and random widths...\n");
    i = 1;
    sleep(sleeptime);
    while (i <= 100)
    {
        d = rand();
        w = rand() % 50;
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%*d) - ", i, w, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%*d) - ", i, w, d));
        if (ret1 != ret2)
        {
            ft_printf("There is a difference in the return value!\n");
            return ;
        }
        i++;
    }
    ft_printf("You succesfully passed all digit with width tests!\n");
    sleep(sleeptime);
    ft_printf("Starting tests with digits and random precisions...\n");
    i = 1;
    sleep(sleeptime);
    while (i <= 100)
    {
        d = rand();
        p = rand() % 50;
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%.*d) - ", i, p, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%.*d) - ", i, p, d));
        if (ret1 != ret2)
        {
            ft_printf("There is a difference in the return value!\n");
            return ;
        }
        i++;
    }
    ft_printf("You succesfully passed all digit with precision tests!\n");
    sleep(sleeptime);
    ft_printf("Starting tests with digits and random widths and precisions...\n");
    i = 1;
    sleep(sleeptime);
    while (i <= 100)
    {
        d = rand();
        p = rand() % 50;
        w = rand() % 50;
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%*.*d) - ", i, w, p, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%*.*d) - ", i, w, p, d));
        if (ret1 != ret2)
        {
            ft_printf("There is a difference in the return value!\n");
            return ;
        }
        i++;
    }
    ft_printf("You succesfully passed all digit with with and precision tests!\n");
    sleep(sleeptime);
    ft_printf("Adding in some flags now...\n");
    i = 1;
    sleep(sleeptime);
    while (i <= 100)
    {
        d = rand();
        p = rand() % 50;
        w = rand() % 50;
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%-*.*d) - ", i, w, p, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%-*.*d) - ", i, w, p, d));
        if (ret1 != ret2)
        {
            ft_printf("There is a difference in the return value!\n");
            return ;
        }
        i++;
    }
    ft_printf("Woah you're good...\n");
    sleep(sleeptime);
    ft_printf("Adding more flags...\n");
    i = 1;
    sleep(sleeptime);
    while (i <= 100)
    {
        d = rand();
        p = rand() % 50;
        w = rand() % 50;
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%0*.*d) - ", i, w, p, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%0*.*d) - ", i, w, p, d));
        if (ret1 != ret2)
        {
            ft_printf("There is a difference in the return value!\n");
            return ;
        }
        i++;
    }
    ft_printf("Okay...\n");
    sleep(sleeptime);
    ft_printf("Lets see if you can handle this...\n");
    i = 1;
    sleep(sleeptime);
    while (i <= 100)
    {
        d = rand();
        p = rand() % 50;
        w = rand() % 50;
        ret1 = printf("return value: (%d) <---- Real Printf\n", printf("test %d: (%-0*.*d) - ", i, w, p, d));
        ret2 = ft_printf("return value: (%d) <---- Your Printf\n", ft_printf("test %d: (%-0*.*d) - ", i, w, p, d));
        if (ret1 != ret2)
        {
            ft_printf("There is a difference in the return value!\n");
            return ;
        }
        i++;
    }
    ft_printf("You passed all my digit tests!\n");
    return ;
}*/
