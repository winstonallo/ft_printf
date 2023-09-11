/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_int_lowercase.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:03:09 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/11 18:59:13 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_puthex_int_lowercase(int value, int asc)
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
	ft_putstr_fd(printout, 1);
	i = ft_strlen(printout);
	free(printout);
	if (value == 0)
		i += ft_putchar_int('0');
	return (i);
}
