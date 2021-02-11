/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_u_create.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 18:34:10 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/11 15:18:43 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static int	pf_utoa_intlen(unsigned int n)
{
	int		len;

	len = 0;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

static char	*pf_utoa(t_params *p, unsigned int n)
{
	char	*newstr;
	int		i;

	if (n == 0 && p->precision == 0)
		return (ft_strdup(""));
	i = pf_utoa_intlen(n);
	newstr = ft_calloc(sizeof(char), i + 1);
	if (!newstr)
		return (NULL);
	i--;
	if (n == 0)
		newstr[i] = '0';
	while (n > 0)
	{
		newstr[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (newstr);
}

int			pf_string_u_create(t_params *p, va_list args)
{
	char	*str;
	char	padder;
	int		ret;

	padder = pf_padder_find(p->flag_zero);
	if (p->precision >= 0 && p->flag_zero)
		padder = ' ';
	str = pf_utoa(p, va_arg(args, unsigned int));
	str = pf_string_expand(str, '0', p->precision, 0);
	str = pf_string_expand(str, padder, p->width, p->flag_minus);
	ret = ft_putstr_fd(str, 1);
	free(str);
	return (ret);
}
