/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_struct_format.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 11:27:39 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/12 16:11:37 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

parameters		read_specifier(parameters input)
{
	input.specifier = *input.str;
	input.str++;
	return (input);
}

parameters	read_asterisks(parameters input, va_list args, int type)
{
	int value;

	value = va_arg(args, int);
	if (value < 0 && type)
	{
		input.flag_minus = 1;
		value = value * -1;
	}
	if (value < 0 && !type)
		input.precision = 0;
	if (type)
		input.width = value;
	else if (value >= 0 && !type)
		input.precision = value;
	input.str++;
	return (input);
}

parameters	read_numbers(parameters input, va_list args, int type)
{
	size_t  len;
	char    *newstr;

	len = 0;
	if (!type && *input.str == '.')
		input.str++;
	if (*input.str == '*')
		return (read_asterisks(input, args, type));
	while (ft_isdigit(input.str[len]))
		len++;
	newstr = ft_substr(input.str, 0, len);
	// do something when substr fails
	if (type)
		input.width = ft_atoi(newstr);
	else
		input.precision = ft_atoi(newstr);
	free(newstr);
	while (len > 0)
	{
		input.str++;
		len--;
	}
	return (input);
}

int			is_flag(char c)
{
	if (c == '-' || c == '0')
		return (1);
	return (0);
}

// Do I need to take into account invalid inputs? Like '++' or ' +'
parameters	read_flags(parameters input)
{
	input.flag_minus = 0;
	input.flag_zero = 0;
	while (is_flag(*input.str))
	{
		if (*input.str == '-')
			input.flag_minus = 1;
		if (*input.str == '0')
			input.flag_zero = 1;
		input.str++;
	}
	return (input);
}

int			is_specifier(char c)
{
	char specifiers[] = { 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%' };
	if (ft_strchr(specifiers, c))
		return (1);
	return (0);
}

int			find_specifier_len(const char *c)
{
	int i;

	i = 0;
	while (!is_specifier(c[i]))
		i++;
	return (i + 1);
}

parameters	make_struct_format(const char *c, va_list args)
{
	parameters params;

	params.len = find_specifier_len(c);
	params.str = ft_strndup(c, params.len); // this can fail
	params = read_flags(params);
	params = read_numbers(params, args, 1);
	params = read_numbers(params, args, 0);
	params = read_specifier(params);
	//print_struct(params);
	free(params.str - params.len);
	return (params);
}
