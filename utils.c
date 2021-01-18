/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 23:06:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/19 00:46:28 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	pf_padder_find(int flag_zero)
{
	if (flag_zero)
		return ('0');
	return (' ');
}
