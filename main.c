/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 10:29:44 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/05 16:40:31 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(const char *c, ...);

int main()
{
    int ret1 = printf("(%s)\n", "Hey");
    int ret2 = ft_printf("(%s)\n", "Hey");
    printf("ret1: %d\nret2: %d\n", ret1, ret2);

    return 0;
}
