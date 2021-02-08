/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 10:29:44 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/08 13:46:27 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	ft_printf(const char *c, ...);

int main()
{
    int ret1 = printf("%3.sdd\n", NULL);
    int ret2 = ft_printf("%3.sdd\n", NULL);
    printf("ret1: %d\nret2: %d\n", ret1, ret2);
    return 0;
}
