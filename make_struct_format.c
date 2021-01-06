/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_struct_format.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 11:27:39 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/06 17:20:11 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

parameters free_str(parameters input, int len)
{
    while (len > 0)
    {
        input.str--;
        len--;
    }
    free(input.str);
    return (input);
}

parameters read_specifier(parameters input)
{
    input.specifier = *input.str;
    input.str++;
    return (input);
}

// TODO: implement *
parameters read_numbers(parameters input, int type)
{
    size_t  len;
    char    *newstr;

    len = 0;
    if (!type && *input.str == '.')
        input.str++;
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

int is_flag(char c)
{
    if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
        return (1);
    return (0);
}

parameters read_flag(parameters input)
{
    if (is_flag(*input.str))
    {
        input.flag = *input.str;
        input.str++;
    }
    else
        input.flag = 0;
    return (input);
}

// do something with va_list, when * is used
parameters  make_struct_format(const char *c, va_list args)
{
    parameters params;
    size_t len;

    params.str = ft_strdup(c);
    len = ft_strlen(params.str);
    params = read_flag(params);
    params = read_numbers(params, 1);
    params = read_numbers(params, 0);
    params = read_specifier(params);
    params = free_str(params, len); // does this free correctly?
    return (params);
}
