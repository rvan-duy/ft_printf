/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 22:09:43 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 12:21:25 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_string_c_create(parameters input, va_list args)
{
	char	*tmp;
	char	*str;

	tmp = ft_calloc(2, sizeof(char));
	tmp[0] = va_arg(args, int);
	if (!tmp[0])
		return (NULL);
	str = pf_string_expand(tmp, ' ', input.width, input.flag_minus);
	free(tmp);
	return (str);
}
