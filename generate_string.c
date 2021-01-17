/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_create.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 21:38:15 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 12:21:00 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*return_error(char specifier)
{
	if (specifier == 'p')
		return (ft_strdup("(nil)"));
	return (NULL);
}

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
		return (return_error(input.specifier));
	return (str);
}
