/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 12:44:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/19 00:18:15 by rvan-duy      ########   odam.nl         */
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
	free(str);
	return (newstr);
}

char	*pf_error_return(char specifier)
{
	if (specifier == 'p')
		return (ft_strdup("(nil)"));
	return (NULL);
}

int		pf_int_negative_to_positive(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char	*pf_strjoin(char const *s1, char const *s2)
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
