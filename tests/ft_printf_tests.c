/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_tests.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 16:48:18 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 18:21:13 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tests.h"

int     main()
{
    /* Testing 2 flags at the same time */
    printf("(%0-20d)\n", 1);
    ft_printf("(%0-20d)\n", 1);
    printf("(%0-20c)\n", 'c');
    ft_printf("(%0-20c)\n", 'c');
    printf("(%0-20s)\n", "string");
    ft_printf("(%0-20s)\n", "string");
    printf("(%0-20u)\n", 1);
    ft_printf("(%0-20u)\n", 1);
    printf("(%0-20x)\n", 1);
    ft_printf("(%0-20x)\n", 1);
    printf("(%0-20X)\n", 1);
    ft_printf("(%0-20X)\n", 1);
    /* Digit tests: any digit
    int max_size = 1000;
    int ret = pf_tests_digits_random(max_size);
    ft_printf("return value of tests: (%d)\n", ret);*/

    /* Digit tests: over max int
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
    printf("- return value: %d\n", printf("%0*.*d ", w, p, u));
    ft_printf("- return value: %d\n", ft_printf("%0*.*d ", w, p, u));
    printf("- return value: %d\n", printf("%0-*.*d ", w, p, u));
    ft_printf("- return value: %d\n", ft_printf("%0-*.*d ", w, p, u));*/

    /* Digit tests: random widths
    int ret = pf_tests_digits_widths_random();
    ft_printf("return value of tests: (%d)\n", ret);*/
    
    //pf_tests_pointers_run();
    //pf_tests_pointers_null_run();
    //int ret = pf_tests_pointers_random();
    //ft_printf("return value of tests: (%d)\n", ret);



    return 0;
}




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
    sleep(sleeptime);
    
    return ;
}*/
