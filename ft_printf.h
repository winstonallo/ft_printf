/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:04:01 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/11 19:19:08 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <bsd/string.h>
# include "./libft/libft.h"

int		ft_printf(const char *s, ...);
int		ft_putstr_int(char *s);
int		ft_putchar_int(char c);
int		ft_putnbr_base(int nbr, char *base);
int		ft_print_adress(unsigned long value, int asc);
int		ft_putnbr_int(int n);
int		ft_puthex_int_lowercase(int value, int asc);
int		ft_puthex_int_uppercase(int value, int asc);
int		ft_putnbr_unsigned_int(unsigned int n);

#endif
