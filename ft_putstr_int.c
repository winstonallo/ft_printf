/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:11:54 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/11 17:12:09 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

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
