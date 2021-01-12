/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 12:44:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/12 13:41:17 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*apply_width(char *str, char padder, parameters input)
{
	int		len;
	char	*tmp;
	char	*newstr;

	len = ft_strlen(str);
	if (len >= input.width)
		newstr = ft_strdup(str);
	else
	{
		tmp = ft_calloc(input.width - len, sizeof(char));
		ft_memset(tmp, padder, input.width - len);
		if (input.flag_minus)
			newstr = ft_strjoin(str, tmp);
		else
			newstr = ft_strjoin(tmp, str);
		free(tmp);
	}
	if (!newstr)
		return (NULL);
	return (newstr);
}
