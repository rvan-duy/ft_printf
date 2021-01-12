/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 22:09:43 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/12 18:42:09 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*generate_c_string(parameters input, va_list args)
{
	char	*tmp;
	char	*str;

	if (!input.width)
		input.width = 1;
	tmp = ft_calloc(2, sizeof(char));
	tmp[0] = va_arg(args, int);
	str = apply_width(tmp, ' ', input);
	free(tmp);
	if (!str)
		return (NULL);
	return (str);
}