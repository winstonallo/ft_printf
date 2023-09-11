/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:28:51 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/11 14:11:11 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_distribute_args(const char *s, void *arg)
{
	int	i;

	i = 0;
	if (*s == 's')
		i += ft_putstr_int((char *) arg);//WORKS:)
	if (*s == 'c')
		i += ft_putchar_int(*(char*) arg);
	if (*s == 'p')//void * pointer in hex
		ft_putstr_fd("yet to be implemented\n", 1);
	if (*s == 'd')//decimal
		ft_putstr_fd("yet to be implemented\n", 1);
	if (*s == 'i')//int
		ft_putnbr_fd(123, 1);
	if (*s == 'u')//unsigned decimal
		ft_putstr_fd("yet to be implemented\n", 1);
	if (*s == 'x')//hex number lowercase
		ft_putstr_fd("yet to be implemented\n", 1);
	if (*s == 'X')//hex number uppercase
		ft_putstr_fd("yet to be implemented\n", 1);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (ft_strchr("cspdiuxX", *s))
				i += ft_distribute_args(s, va_arg(args, void *));
			else if (*s == '%')
				i += ft_putchar_int('%');
		}
		else
		{
			i = i + ft_putchar_int(*s);
		}
		s++;

	}
	va_end(args);
	return (i);
}
