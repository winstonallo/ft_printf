/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_int_lowercase.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:03:09 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/11 17:35:57 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_fill_string(int value, int *strlen)
{
	int		i;
	int		temp;
	char	*str;

	i = 0;
	temp = value;
	if (value < 0)
	{
		while (temp < -0)
		{
			temp /= 16;
			i++;
		}
		*strlen = i;
		str = calloc(i + 1, sizeof(char));
		return (str);
	}
	while (temp != 0)
	{
		temp /= 16;
		i++;
	}
	*strlen = i;
	str = calloc(i + 1, sizeof(char));
	return (str);
}


int	ft_puthex_int_lowercase(int value, int asc)
{
	unsigned long	temp;
	char			*res;
	int				i;
	int				*strlen;

	strlen = &i;
	temp = value;
	res = ft_fill_string(value, strlen);
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
	ft_putstr_fd(res, 1);
	free(res);
	if (value == 0)
		i += ft_putchar_int('0');
	return (i);
}
