/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   digits.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 10:49:38 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/19 00:18:07 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*pf_string_d_create_positive(int d, parameters input, char padder)
{
	char	*str;

	str = ft_itoa(d);
	str = pf_string_expand(str, '0', input.precision, 0);
	str = pf_string_expand(str, padder, input.width, input.flag_minus);
	return (str);
}

static char	*pf_string_d_create_negative(int d, parameters input, char padder)
{
	char	*str;

	d = pf_int_negative_to_positive(d);
	str = ft_itoa(d);
	str = pf_string_expand(str, '0', input.precision, 0);
	if (!input.flag_zero)
		str = pf_strjoin("-", str);
	str = pf_string_expand(str, padder, input.width, input.flag_minus);
	if (input.flag_zero)
		str[0] = '-';
	return (str);
}

char		*pf_string_d_create(parameters input, va_list args)
{
	char	*tmp;
	char	padder;
	int		d;

	if (input.flag_zero && input.precision > 0)
		input.flag_zero = 0;
	padder = pf_padder_find(input.flag_zero);
	d = va_arg(args, int);
	if (d < 0)
		return (pf_string_d_create_negative(d, input, padder));
	return (pf_string_d_create_positive(d, input, padder));
}
