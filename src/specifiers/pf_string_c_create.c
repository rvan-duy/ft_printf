/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_c_create.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 11:01:10 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/29 23:36:23 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	pf_putwidth(int width)
{
	int		i;

	i = 1;
	while (i < width)
		i += ft_putchar_fd(' ', 1);
	return (width);
}

int			pf_string_c_create(t_params *p, va_list args)
{
	char	c;
	int		ret;

	ret = 0;
	c = va_arg(args, int);
	if (p->width > 1)
	{
		if (p->flag_minus)
		{
			ret += ft_putchar_fd(c, 1);
			ret += pf_putwidth(p->width);
		}
		else
		{
			ret += pf_putwidth(p->width);
			ret += ft_putchar_fd(c, 1);
		}
		return (ret - 1);
	}
	else
		return (ft_putchar_fd(c, 1));
}
