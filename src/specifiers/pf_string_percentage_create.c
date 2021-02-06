/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_string_percentage_create.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 17:53:10 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/06 18:00:42 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_string_percentage_create(t_params *p)
{
    char    *str;
    char    padder;
    int     ret;

    if (p->flag_zero && p->precision >= 0)
		p->flag_zero = 0;
    padder = pf_padder_find(p->flag_zero);
    str = ft_strdup("%");
    str = pf_string_expand(str, padder, p->width, p->flag_minus);
    ret = ft_putstr_fd(str, 1);
    free(str);
    ret = (ret == 0 && str == NULL) ? -1 : ret; // change
    return (ret);
}