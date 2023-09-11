/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:28:51 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/11 17:55:25 by abied-ch         ###   ########.fr       */
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
		i += ft_putchar_int(*(char *) &arg);
	else if (*s == 'p')//void * pointer in hex
		i += ft_print_adress((unsigned long) arg, 87);
	else if (*s == 'd' || *s == 'i')//decimal
		i += ft_putnbr_int(*(int *) &arg);
	else if (*s == 'u')//unsigned decimal
		ft_putstr_fd("yet to be implemented\n", 1);
	else if (*s == 'x')//hex number lowercase
		i += ft_puthex_int_lowercase(*(int *) &arg, 87);
	else if (*s == 'X')//hex number uppercase
		i += ft_puthex_int_uppercase(*(int *) &arg, 87);
	return (i);
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
			{
				i += ft_distribute_args(s, va_arg(args, void *));
			}
			else if (*s == '%')
				i += ft_putchar_int('%');
		}
		else
		{
			i += ft_putchar_int(*s);
		}
		s++;

	}
	va_end(args);
	return (i);
}
