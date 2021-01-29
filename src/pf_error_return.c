/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_error_return.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 12:01:24 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/29 12:07:52 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     pf_error_return(char specifier)
{
	if (specifier == 'p')
		return (ft_putstr_fd("(nil)", 1));
	return (0);
}
