/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_create.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 00:46:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/19 00:47:01 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_string_create(parameters input, va_list args)
{
	char *str;

	if (input.specifier == 'c')
		str = pf_string_c_create(input, args);
	if (input.specifier == 'd' || input.specifier == 'i')
		str = pf_string_d_create(input, args);
	if (input.specifier == 's')
		str = pf_string_s_create(input, args);
	if (input.specifier == 'u')
		str = pf_string_u_create(input, args);
	if (input.specifier == 'x' || input.specifier == 'X')
		str = pf_string_x_create(input, args);
	if (input.specifier == 'p')
		str = pf_string_p_create(input, args);
	if (input.specifier == '%')
		str = ft_strdup("%");
	if (!str)
		return (pf_error_return(input.specifier));
	return (str);
}
