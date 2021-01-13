/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   digits.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 10:49:38 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/13 16:31:23 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*generate_d_string(parameters input, va_list args)
{
	char	*tmp1;
	char	*tmp2;
	char	*str;
	char	padder;

	padder = find_padder(input.flag_zero);
	if (!input.width)
		input.width = 1;
	tmp1 = ft_itoa(va_arg(args, int));
	if (!tmp1)
		return (NULL);
	tmp2 = expand_str(tmp1, '0', input.precision, 0);
	free(tmp1);
	if (!tmp2)
		return (NULL);
	str = expand_str(tmp2, padder, input.width, input.flag_minus);
	free(tmp2);
	if (!str)
		return (NULL);
	return (str);
}
