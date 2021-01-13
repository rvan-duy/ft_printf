/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 16:48:18 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/13 17:44:06 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    main()
{
    int i;
    int d;
    int w;
    int ret1;
    int ret2;

    i = 1;
    printf("Starting tests with small digits...\n");
    sleep(2);
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
        usleep(50000);
        ft_printf("\e[1;1H\e[2J");
        i++;
    }
    ft_printf("You succesfully passed all small digit tests!\n");
    sleep(2);
    ft_printf("Starting tests with big digits...\n");
    i = 0;
    sleep(2);
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
        usleep(50000);
        ft_printf("\e[1;1H\e[2J");
        i++;
    }
    ft_printf("You succesfully passed all big digit tests!\n");
    sleep(2);
    ft_printf("Starting tests with digits and random widths...\n");
    i = 0;
    sleep(2);
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
        usleep(50000);
        ft_printf("\e[1;1H\e[2J");
        i++;
    }
    ft_printf("You succesfully passed all digit with width tests!\n");
    return ;
}
