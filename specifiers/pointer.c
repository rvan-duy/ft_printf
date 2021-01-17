/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 18:15:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/17 12:23:12 by rvan-duy      ########   odam.nl         */
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

char	*pf_string_p_create(parameters input, va_list args)
{
	char			*str;
	static int 		i = 0;
	char			*tmp1;
	char			*tmp2;
	char			*tmp3;
	char			padder;
	void			*ptr;
	unsigned long	ptr_value;

	if (input.flag_minus && input.flag_zero)
		input.flag_zero = 0;
	padder = pf_padder_find(input.flag_zero);
	ptr = va_arg(args, void*);
	ptr_value = (unsigned long)ptr;
	tmp1 = ltox(ptr_value);
	if (!tmp1)
		return (NULL);
	tmp2 = pf_string_expand(tmp1, '0', input.precision, 0);
	/*if (i == 0)
	{
		write(1, "lets fail malloc!", ft_strlen("lets fail malloc!"));
		tmp2 = NULL;
		i++;
	}*/
	free(tmp1);
	if (!tmp2)
		return (NULL);
	tmp3 = ft_strjoin("0x", tmp2);
	free(tmp2);
	if (!tmp3)
		return (NULL);
	str = pf_string_expand(tmp3, padder, input.width, input.flag_zero);
	free(tmp3);
	return (str);
}
