/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:28:51 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/09 16:09:10 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_distribute_args(void **arr, int c)
{
	int* intArr = (int*)arr;
	if (c == 's' || c == 'c')//string
		ft_putstr_fd(*arr, 1);
	if (c == 'p')//void * pointer in hex
		ft_putstr_fd("yet to be implemented\n", 1);
	if (c == 'd')//decimal
		ft_putstr_fd("yet to be implemented\n", 1);
	if (c == 'i')//int
		ft_putnbr_fd(*intArr, 1);
	if (c == 'u')//unsigned decimal
		ft_putstr_fd("yet to be implemented\n", 1);
	if (c == 'x')//hex number lowercase
		ft_putstr_fd("yet to be implemented\n", 1);
	if (c == 'X')//hex number uppercase
		ft_putstr_fd("yet to be implemented\n", 1);
	if (c == '%')//%
		ft_putchar_fd('%', 1);
}

void	ft_parse_string(void **arr, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i += 2;
			ft_distribute_args(arr, s[i]);
			arr++;
		}
		ft_putchar_fd(s[i], 1);
		i++;
	}
}

int	ft_count_arguments(const char *s)
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
	return (1);
}
