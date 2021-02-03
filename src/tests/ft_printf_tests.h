/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_tests.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 16:17:05 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/03 14:09:35 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

# define uint unsigned int

void    pf_tests_digits_random_flags();
void    pf_tests_digits_0flag_precision();
int     pf_tests_digits_random(int max_size);
int     pf_tests_digits_widths_random();
void    pf_tests_digits_negatives();
void    pf_tests_digits_over_max();
int     pf_tests_char_all();
void    pf_tests_char_random();
void    pf_tests_strings_random();
void    pf_tests_pointers_run();
void    pf_tests_pointers_null_run();
int     pf_tests_pointers_random();
