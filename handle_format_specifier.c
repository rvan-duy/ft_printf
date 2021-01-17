/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_format_specifier.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 17:19:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/16 23:48:21 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_format_specifier(const char *c, va_list args, lengths *lens)
{
	parameters	params;
	char		*str;

	c++;
	params = make_struct_format(c, args);
	str = generate_string(params, args); // if str = NULL?
	if (!str)
		return ;
	ft_putstr_fd(str, 1);
	lens->specifier = params.len + 1;
	lens->str = lens->str + ft_strlen(str);
	return ;
}
