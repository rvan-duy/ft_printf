/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hexadecimal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 11:27:49 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/14 17:35:33 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

char		*generate_x_string(parameters input, va_list args)
{
	char	*str;
	char	padder;
	int		decimal;
	char	*tmp1;
	char	*tmp2;

	padder = find_padder(input.flag_zero);
	if (!input.width)
		input.width = 1;
	decimal = va_arg(args, unsigned int);
	tmp1 = itox(decimal, input.specifier);
	if (!tmp1)
		return (NULL);
	tmp2 = expand_str(tmp1, '0', input.precision, 0);
	free(tmp1);
	if (!tmp2)
		return (NULL);
	str = expand_str(tmp2, padder, input.width, input.flag_minus);
	free(tmp2);
	if (!str)
		return (NULL);
	return (str);
}
