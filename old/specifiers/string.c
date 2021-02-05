/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 18:33:59 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/05 13:04:22 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_string_s_create(parameters input, va_list args)
{
	char *str;

	str = va_arg(args, char*);
	str = pf_string_expand(str, ' ', input.width, input.flag_minus);
	return (str);
}
