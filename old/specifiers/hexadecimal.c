/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hexadecimal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 11:27:49 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/05 13:04:22 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*itox(unsigned int n, char specifier)
{
	char	*str;
	char	*counters;
	int		len;

	if (!n)
		return (ft_strdup("0"));
	if (specifier == 'x')
		counters = ft_strdup(HEXADECIMALS_LOWER);
	if (specifier == 'X')
		counters = ft_strdup(HEXADECIMALS_UPPER);
	if (!counters)
		return (NULL);
	len = hex_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	len -= 1;
	while (n > 0)
	{
		str[len] = counters[n % 16];
		n /= 16;
		len--;
	}
	return (str);
}

char		*pf_string_x_create(parameters input, va_list args)
{
	char	*str;
	char	padder;
	int		decimal;

	padder = pf_padder_find(input.flag_zero);
	decimal = va_arg(args, unsigned int);
	str = itox(decimal, input.specifier);
	str = pf_string_expand(str, '0', input.precision, 0);
	str = pf_string_expand(str, padder, input.width, input.flag_minus);
	return (str);
}
