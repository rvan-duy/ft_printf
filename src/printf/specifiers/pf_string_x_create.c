/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_x_create.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 17:45:51 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/12 14:41:10 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h> // free

static int	hex_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 16)
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

static char	*itox(unsigned int n, t_params *p)
{
	int		len;
	char	*str;

	if (n == 0 && p->precision == 0)
		return (ft_strdup(""));
	len = hex_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	put_hex(str, len - 1, n, p->specifier);
	return (str);
}

int	pf_string_x_create(t_params *p, va_list args)
{
	char	*str;
	char	padder;
	int		decimal;
	int		ret;

	padder = pf_padder_find(p->flag_zero);
	if (p->precision >= 0 && p->flag_zero)
		padder = ' ';
	decimal = va_arg(args, unsigned int);
	str = itox(decimal, p);
	str = pf_string_expand(str, '0', p->precision, 0);
	str = pf_string_expand(str, padder, p->width, p->flag_minus);
	ret = ft_putstr_fd(str, 1);
	free(str);
	return (ret);
}
