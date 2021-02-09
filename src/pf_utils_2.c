/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_utils_2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 10:50:34 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/09 11:14:38 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_asterisk_read(t_params *p, va_list args, char type)
{
	int		value;

	value = va_arg(args, int);
	p->str++;
	if (value < 0 && type == WIDTH)
	{
		p->flag_minus = 1;
		value *= -1;
	}
	if (value < 0 && type == PRECISION)
		return (-1);
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

char		*pf_strjoin(char const *s1, char *s2)
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

int			pf_ret_return(int ret, char *str)
{
	if (ret == 0 && str == NULL)
		return (-1);
	return (ret);
}
