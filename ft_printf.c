/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:28:51 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/09 15:43:17 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_parse_string(void **arr, char *s)
{
	
}

int	ft_count_arguments(char *s)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s == '%')
			count++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	char	**arguments;
	int		arg_count;

	arg_count = ft_count_arguments(s);
	va_start(args);
	arguments[i] = va_arg(args);
	while (++i < count)
		arguments[i] = va_arg(args);
	ft_parse_string(arr, s);
	va_end(args);
	return (result);
}
