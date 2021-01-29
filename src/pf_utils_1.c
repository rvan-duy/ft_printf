/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_utils_1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 01:42:04 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/29 13:21:05 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_specifier_len(const char *c, t_params *p)
{
	int		i;
	char	*sp;

	i = 0;
	p->paramlen = 0;
	sp = ft_strdup(SPECIFIERS);
	if (!sp)
		return (0);
	while (!ft_strchr(sp, c[i]) || c[i] == '\0')
		i++;
	p->paramlen = i + 1;
	return (1);
}

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
	if (p->flag_minus && p->flag_zero)
		p->flag_zero = 0;
}

void		pf_specifier_read(t_params *p)
{
	p->specifier = *p->str;
	p->str++;
	return ;
}
