/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 23:06:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 01:09:31 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    find_padder(int flag_zero)
{
	if (flag_zero)
		return ('0');
	return (' ');
}
