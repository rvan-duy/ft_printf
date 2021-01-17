/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_string.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 21:38:15 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/16 18:13:31 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*generate_string(parameters input, va_list args)
{
	char *str;

	if (input.specifier == 'c')
		str = generate_c_string(input, args);
	if (input.specifier == 'd' || input.specifier == 'i')
		str = generate_d_string(input, args);
	if (input.specifier == 's')
		str = generate_s_string(input, args);
	if (input.specifier == 'u')
		str = generate_u_string(input, args);
	if (input.specifier == 'x' || input.specifier == 'X')
		str = generate_x_string(input, args);
	if (input.specifier == 'p')
		str = generate_p_string(input, args);
	if (input.specifier == '%')
		str = ft_strdup("%");
	if (!str)
		return (NULL);
	return (str);
}
