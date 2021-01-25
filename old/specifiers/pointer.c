/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 18:15:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/25 20:48:02 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	hex_len(unsigned long n)
{
	int				len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*ltox(unsigned long n)
{
	char			*str;
	char			*counters;
	int				len;

	if (!n)
		return (NULL);
	counters = ft_strdup(HEXADECIMALS_LOWER);
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

char		*pf_string_p_create(parameters input, va_list args)
{
	char			*str;
	char			padder;
	void			*ptr;
	unsigned long	ptr_value;

	if (input.flag_zero && !input.precision)
		input.precision = input.width - 2;
	if (input.flag_zero)
		input.flag_zero = 0;
	padder = pf_padder_find(input.flag_zero);
	ptr = va_arg(args, void*); // niet nodig
	ptr_value = (unsigned long)ptr;
	str = ltox(ptr_value);
	str = pf_string_expand(str, '0', input.precision, 0);
	str = pf_strjoin("0x", str);
	if (!str)
		str = pf_error_return('p');
	str = pf_string_expand(str, padder, input.width, input.flag_minus);
	return (str);
}
