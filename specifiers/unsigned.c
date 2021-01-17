/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsigned.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 22:59:13 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 01:30:40 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*generate_u_string(parameters input, va_list args)
{
	char	*str;
	char	*tmp;
	char	padder;

	padder = find_padder(input.flag_zero);
	tmp = ft_utoa(va_arg(args, unsigned int));
	if (!tmp)
		return (NULL);
	str = expand_str(tmp, padder, input.width, input.flag_minus);
	free(tmp);
	return (str);
}
