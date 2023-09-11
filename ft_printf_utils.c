/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:03:09 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/11 13:20:02 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_putchar_int(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_int(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		write(1, s, 1);
		i++;
		s++;
	}
	return (i);
}