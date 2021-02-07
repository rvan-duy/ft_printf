/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_d_create.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 17:17:50 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/07 16:52:31 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_string_d_create_positive(int d, t_params *p, char padder)
{
	char	*str;
	int 	ret;

	if (d == 0 && p->precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa(d);
	str = pf_string_expand(str, '0', p->precision, 0);
	str = pf_string_expand(str, padder, p->width, p->flag_minus);
	ret = ft_putstr_fd(str, 1);
	free(str);
	return (ret);
}

static int	pf_int_negative_to_positive(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static int	pf_string_d_create_negative(int d, t_params *p, char padder)
{
	char	*str;
	int 	ret;

	d = pf_int_negative_to_positive(d);
	if (d != INT_MIN)
		str = ft_itoa(d);
	else
		str = ft_strdup("2147483648");
	str = pf_string_expand(str, '0', p->precision, 0);
	if (!p->flag_zero)
		str = pf_strjoin("-", str);
	str = pf_string_expand(str, padder, p->width, p->flag_minus);
	if (p->flag_zero && str[0] == '0')
		str[0] = '-';
	else if (p->flag_zero && str[0] != '0')
		str = pf_strjoin("-", str);
	ret = ft_putstr_fd(str, 1);
	free(str);
	return (ret);
}

int			pf_string_d_create(t_params *p, va_list args)
{
	char	padder;
	int		d;

	if (p->flag_zero && p->precision >= 0)
		p->flag_zero = 0;
	padder = pf_padder_find(p->flag_zero);
	d = va_arg(args, int);
	if (d < 0)
		return (pf_string_d_create_negative(d, p, padder));
	return (pf_string_d_create_positive(d, p, padder));
}
