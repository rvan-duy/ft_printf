/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 18:15:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 00:57:40 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	hex_len(unsigned long n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*ltox(unsigned long n)
{
	char	*str;
	char	*counters;
	int		len;

	if (!n)
		return (NULL);
	counters = ft_strdup(HEXADECIMALS_LOWER);
	if (!counters)
		return (NULL);
	len = hex_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	len -= 1;
	while (n > 0)
	{
		str[len] = counters[n % 16];
		n /= 16;
		len--;
	}
	return (str);
}

char	*generate_p_string(parameters input, va_list args)
{
	char			*str;
	void			*ptr;
	unsigned long	ptr_value;

	if (!input.width)
		input.width = 1;
	ptr = va_arg(args, void*);
	ptr_value = (unsigned long)ptr;
	str = ltox(ptr_value);
	if (!str)
		return (ft_strdup("(nil)"));
	
	return (str);
}
