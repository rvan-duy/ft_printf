/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_utils_1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 01:42:04 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/11 17:43:46 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void		pf_flags_read(t_params *p)
{
	p->flag_minus = 0;
	p->flag_zero = 0;
	while (*p->str == '-' || *p->str == '0')
	{
		if (*p->str == '-')
			p->flag_minus = 1;
		if (*p->str == '0')
			p->flag_zero = 1;
		p->str++;
	}
}

int			pf_specifier_read(t_params *p)
{
	if (ft_strchr(SPECIFIERS, *p->str))
	{
		p->specifier = *p->str;
		p->str++;
		return (1);
	}
	return (0);
}
