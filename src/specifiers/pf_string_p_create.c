/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_p_create.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 18:36:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/09 12:11:29 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	string_p_hex_len(unsigned long long n)
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

static void	string_p_put_hex(char *str, int len, unsigned long long n)
{
	if (n >= 16)
		string_p_put_hex(str, len - 1, n / 16);
	n %= 16;
	if (n >= 10)
		str[len] = n + 87;
	else
		str[len] = n + 48;
}

static char	*string_p_itox(unsigned long long n)
{
	char	*str;
	int		len;

	if (!n)
		return (ft_strdup("0"));
	len = string_p_hex_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	string_p_put_hex(str, len - 1, n);
	return (str);
}

int			pf_string_p_create(t_params *p, va_list args)
{
	char	*str;
	char	*tmp;
	char	padder;
	int		ret;

	if (p->flag_zero && !p->precision)
		p->precision = p->width - 2;
	if (p->flag_zero)
		p->flag_zero = 0;
	padder = pf_padder_find(p->flag_zero);
	tmp = string_p_itox(va_arg(args, unsigned long long));
	tmp = pf_string_expand(tmp, '0', p->precision, 0);
	str = pf_strjoin("0x", tmp);
	str = pf_string_expand(str, padder, p->width, p->flag_minus);
	ret = ft_putstr_fd(str, 1);
	free(str);
	return (ret);
}
