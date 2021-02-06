/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 10:29:44 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/06 18:35:01 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *c, ...);

int main()
{
    unsigned int u = 0;
    int ret1 = printf("(%.0u)\n", u);
    int ret2 = ft_printf("(%0.0u)\n", u);
    printf("ret1: %d\nret2: %d\n", ret1, ret2);

    return 0;
}
