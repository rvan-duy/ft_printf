/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 14:25:23 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/01 14:31:57 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t count, size_t size)
{
	void *newptr;

	newptr = ft_calloc(count, size);
	ft_memcpy(newptr, ptr, count);
	free(ptr);
	ptr = NULL;
	return (newptr);
}
