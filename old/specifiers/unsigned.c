/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsigned.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 22:59:13 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/05 13:04:22 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_string_u_create(parameters input, va_list args)
{
	char	*str;
	char	padder;

	padder = pf_padder_find(input.flag_zero);
	str = ft_utoa(va_arg(args, unsigned int));
	str = pf_string_expand(str, padder, input.width, input.flag_minus);
	return (str);
}
