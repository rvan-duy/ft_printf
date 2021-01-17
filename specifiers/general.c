/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 12:44:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 13:43:40 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*pf_string_expand(char *str, char padder, int range, int flag_minus)
{
	int		len;
	char	*tmp;
	char	*newstr;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len >= range)
		return (ft_strdup(str));
	tmp = ft_calloc(range - len + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	ft_memset(tmp, padder, range - len);
	if (flag_minus)
		newstr = ft_strjoin(str, tmp);
	else
		newstr = ft_strjoin(tmp, str);
	free(tmp);
	return (newstr);
}

char	*pf_error_return(char specifier)
{
	if (specifier == 'p')
		return (ft_strdup("(nil)"));
	return (NULL);
}
