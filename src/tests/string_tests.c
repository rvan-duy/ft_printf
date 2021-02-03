/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_tests.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 14:06:31 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/03 14:40:44 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tests.h"

void    pf_tests_strings_random()
{
    char *c = ft_strdup("Hey");

    printf("(%-s)\n", c);
    ft_printf("(%-s)\n", c);
    printf("(%-9s)\n", c);
    ft_printf("(%-9s)\n", c);
    printf("(%-0s)\n", c);
    ft_printf("(%-0s)\n", c);
    printf("(%-1s)\n", c);
    ft_printf("(%-1s)\n", c);
    printf("(%9s)\n", c);
    ft_printf("(%9s)\n", c);
    printf("(%-09s)\n", c);
    ft_printf("(%-09s)\n", c);
    return ;
}
