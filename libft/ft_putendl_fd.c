/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 12:39:48 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/02/09 13:30:33 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl_fd(char *s, int fd)
{
	int ret;

	if (!s)
		return (0);
	ret = ft_putstr_fd(s, fd);
	if (write(fd, "\n", 1) < 0)
		ret = -1;
	else
		ret += 1;
	return (ret);
}
