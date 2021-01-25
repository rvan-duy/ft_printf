/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_utils_1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 01:42:04 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/25 22:33:15 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			pf_specifier_len(const char *c, t_params *p)
{
	int		i;
	char	*sp;

	i = 0;
	p->len = 0;
	sp = ft_strdup(SPECIFIERS);
	if (!sp)
		return (0);
	while (!ft_strchr(sp, c[i]) || c[i] == '\0')
		i++;
	p->len = i + 1;
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

static int pf_asterisk_read(t_params *p, va_list args, char type)
{
	int value;

	value = va_arg(args, int);
	p->str++;
	if (value < 0 && type == WIDTH)
	{
		p->flag_minus = 1;
		value *= -1;
	}
	if (value < 0 && type == PRECISION)
		return (0);
	return (value);
}

void		pf_width_read(t_params *p, va_list args)
{
	if (*p->str == '*')
		p->width = pf_asterisk_read(p, args, WIDTH);
	else
		p->width = ft_atoi(p->str);
	while (ft_isdigit(*p->str))
		p->str++;
	return ;
}

void		pf_precision_read(t_params *p, va_list args)
{
	if (*p->str == '.')
		p->str++;
	else
		return ;
	if (*p->str == '*')
		p->precision = pf_asterisk_read(p, args, PRECISION);
	else
		p->precision = ft_atoi(p->str);
	while (ft_isdigit(*p->str))
		p->str++;
}

void		pf_specifier_read(t_params *p)
{
	p->specifier = *p->str;
	p->str++;
	return ;
}

char	*pf_strjoin(char const *s1, char *s2)
{
	char	*newstr;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, len1 + 1);
	ft_strlcat(newstr, s2, len1 + len2 + 1);
	free(s2);
	return (newstr);
}
