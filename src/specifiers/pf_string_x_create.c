/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_x_create.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 17:45:51 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/25 20:47:22 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

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

static void	put_hex(char *str, int len, unsigned int n, char specifier)
{
	if (n >= 16)
		put_hex(str, len - 1, n / 16, specifier);
	n %= 16;
	if (n >= 10)
	{
		if (specifier == 'x')
			str[len] = n + 87;
		else if (specifier == 'X')
			str[len] = n + 55;
	}
	else
		str[len] = n + 48;
}

static char	*itox(unsigned int n, char specifier)
{
	int		len;
	char	*str;

	len = hex_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	put_hex(str, len - 1, n, specifier);
	return (str);
}

char		*pf_string_x_create(t_params *p, va_list args)
{
	char	*str;
	char	padder;
	int		decimal;

	padder = pf_padder_find(p->flag_zero);
	decimal = va_arg(args, unsigned int);
	str = itox(decimal, p->specifier);
	str = pf_string_expand(str, '0', p->precision, 0);
	str = pf_string_expand(str, padder, p->width, p->flag_minus);
	return (str);
}