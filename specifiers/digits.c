/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   digits.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 10:49:38 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 12:23:12 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_string_d_create(parameters input, va_list args)
{
	char	*tmp1;
	char	*tmp2;
	char	*str;
	char	padder;

	padder = pf_padder_find(input.flag_zero);
	tmp1 = ft_itoa(va_arg(args, int));
	if (!tmp1)
		return (NULL);
	tmp2 = pf_string_expand(tmp1, '0', input.precision, 0);
	free(tmp1);
	if (!tmp2)
		return (NULL);
	str = pf_string_expand(tmp2, padder, input.width, input.flag_minus);
	free(tmp2);
	return (str);
}
