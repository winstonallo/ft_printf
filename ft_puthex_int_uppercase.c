/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_int_uppercase.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:36:25 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/11 18:59:12 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_hex_toupper(char *s)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(ft_strlen(s) + 1);
	while (s[i])
	{
		if (s[i] <= 'z' && s[i] >= 'a')
			new[i] = s[i] - 32;
		else
			new[i] = s[i];
		i++;
	}
	return (new);
}

static char	*create_string(unsigned int value, int *strlen)
{
	int				i;
	unsigned int	temp;
	char			*str;

	i = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (str);
}

int	ft_puthex_int_uppercase(int value, int asc)
{
	unsigned int	tempval;
	char			*printout;
	int				i;
	int				*iptr;

	iptr = &i;
	tempval = value;
	printout = create_string(value, iptr);
	if (!printout)
		return (0);
	while (tempval != 0)
	{
		if ((tempval % 16) < 10)
			printout[i] = (tempval % 16) + 48;
		else
			printout[i] = (tempval % 16) + asc;
		tempval = tempval / 16;
		i--;
	}
	ft_putstr_fd(ft_hex_toupper(printout), 1);
	i = ft_strlen(printout);
	free(printout);
	if (value == 0)
		i += ft_putchar_int('0');
	return (i);
}
