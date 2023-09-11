/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:13:48 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/11 18:59:16 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_fill_string(unsigned long value, int *strlen)
{
	int				i;
	unsigned long	temp;
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

int	ft_print_adress(unsigned long value, int asc)
{
	unsigned long	temp;
	char			*res;
	int				i;
	int				*iptr;

	iptr = &i;
	temp = value;
	res = ft_fill_string(value, iptr);
	if (!res)
		return (0);
	while (temp != 0 && i-- >= 0)
	{
		if ((temp % 16) < 10)
			res[i + 1] = (temp % 16) + 48;
		else
			res[i + 1] = (temp % 16) + asc;
		temp = temp / 16;
	}
	i = ft_strlen(res);
	i = i + ft_putstr_int("0x");
	ft_putstr_fd(res, 1);
	free(res);
	if (value == 0)
		i += ft_putchar_int('0');
	return (i);
}
