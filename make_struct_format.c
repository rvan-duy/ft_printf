/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_struct_format.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 11:27:39 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/11 15:44:39 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int count_flags(char *str)
{
    int i;
   
    i = 0;
    while (is_flag(str[i]))
        i++;
    return (i);
}

// Do I need to take into account invalid inputs? Like '++' or ' +'
parameters read_flags(parameters input)
{
    int i;
    int flag_count;

    flag_count = count_flags(input.str);
    i = 0;
    input.flags = ft_calloc(flag_count + 1, sizeof(char));
    while (flag_count > 0)
    {
        input.flags[i] = *input.str;
        input.str++;
        i++;
        flag_count--;
    }
    return (input);
}

int is_specifier(char c)
{
    char specifiers[] = { 'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%' };
    if (ft_strchr(specifiers, c))
        return (1);
    return (0);
}

int find_specifier_len(const char *c)
{
    int i;

    i = 1;
    while (!is_specifier(c[i]))
        i++;
    return (i + 1);
}

// do something with va_list, when * is used
parameters  make_struct_format(const char *c, va_list args)
{
    parameters params;

    params.len = find_specifier_len(c);
    params.str = ft_strndup(c, params.len);
    params = read_flags(params);
    params = read_numbers(params, 1);
    params = read_numbers(params, 0);
    params = read_specifier(params);
    print_struct(params);
    free(params.str - params.len);
    return (params);
}
