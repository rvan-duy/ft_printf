/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 18:33:59 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 12:21:25 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_string_s_create(parameters input, va_list args)
{
	char *str;
	char *tmp;

	tmp = va_arg(args, char*);
	str = pf_string_expand(tmp, ' ', input.width, input.flag_minus);
	return (str);
}
