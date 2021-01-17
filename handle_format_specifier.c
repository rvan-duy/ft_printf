/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_format_specifier_handler.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 17:19:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 12:24:39 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_format_specifier_handler(const char *c, va_list args, lengths *lens)
{
	parameters	params;
	char		*str;

	c++;
	params = pf_struct_format_create(c, args);
	str = pf_string_create(params, args); // if str = NULL?
	if (!str)
		return ;
	ft_putstr_fd(str, 1);
	lens->specifier = params.len + 1;
	lens->str = lens->str + ft_strlen(str);
	return ;
}
