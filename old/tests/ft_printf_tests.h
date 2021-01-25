/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_tests.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 16:17:05 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 17:15:23 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define uint unsigned int

int     pf_tests_digits_random(int max_size);
int     pf_tests_digits_widths_random();
void    pf_tests_pointers_run();
void    pf_tests_pointers_null_run();
int     pf_tests_pointers_random();