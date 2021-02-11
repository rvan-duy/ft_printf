/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_utils_1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 01:42:04 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/11 16:19:40 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int			pf_specifier_len(const char *c, t_params *p)
{
	int		i;

	i = 0;
	p->len = 0;
	while (c[i])
	{
		if (ft_strchr(SPECIFIERS, c[i]))
		{
			p->len = i + 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void		pf_flags_read(const char *c, t_params *p)
{
	p->flag_minus = 0;
	p->flag_zero = 0;
	while (*p->str == '-' || *p->str == '0')
	{
		if (*p->str == '-')
			p->flag_minus = 1;
		if (*p->str == '0')
			p->flag_zero = 1;
		c++;
		p->len++;
	}
	if (p->flag_minus && p->flag_zero)
		p->flag_zero = 0;
}

void		pf_specifier_read(t_params *p)
{
	p->specifier = *p->str;
	p->str++;
	return ;
}
