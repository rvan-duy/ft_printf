/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_u_create.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 18:34:10 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/03 14:55:09 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		pf_string_u_create(t_params *p, va_list args)
{
	char	*str;
	char	padder;
	int		ret;

	padder = pf_padder_find(p->flag_zero);
	str = ft_utoa(va_arg(args, unsigned int));
	str = pf_string_expand(str, padder, p->width, p->flag_minus);
	ret = ft_putstr_fd(str, 1);
	free(str);
	return (ret);
	return (ft_putstr_fd(str, 1));
}
