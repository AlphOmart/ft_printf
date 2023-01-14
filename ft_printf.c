/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:55:48 by mwubneh           #+#    #+#             */
/*   Updated: 2023/01/14 17:30:20 by mwubneh          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_reverse_base(char *base, int len_base)
{
	int		i;
	char	*new_base;

	new_base = NULL;
	i = 0;
	while (len_base)
		new_base[len_base - i] = base[i];
	return (*new_base);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr *= -1);
	return (nbr);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr_base(int64_t nbr, char *base)
{
	int		len_base;
	int		c;

	c = 0;
	len_base = ft_strlen(base);
	if (nbr < 0)
	{
		if (len_base == 10)
			c += write (1, "-", 1);
		else if (len_base == 16)
			*base = ft_reverse_base(base, 16);
		nbr *= -1;
	}
	if (len_base <= nbr)
	{
		c += ft_putnbr_base(nbr / len_base, base);
		c += ft_putnbr_base(nbr % len_base, base);
	}
	else
	{
		c += write(1, &base[nbr], 1);
	}
	return (c);
}

int	ft_print_str(const char	*str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_print_str("(null)"));
	while (str[i])
		write (1, &str[i++], 1);
	return (i);
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_cont(char c, va_list arg)
{
	if (c == 's')
		return (ft_print_str(va_arg(arg, char *)));
	if (c == '%')
		return (ft_print_char('%'));
	if (c == 'c')
		return (ft_print_char((char) va_arg(arg, int)));
	if (c == 'i' || c == 'd')
		return (ft_putnbr_base(va_arg(arg, int), "0123456789"));
	if (c == 'u')
		return (ft_putnbr_base(ft_abs(va_arg(arg, int)), "0123456879"));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(arg, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(arg, int), "0123456789ABCDEF"));
	return (0);
}

int	val_format(char c)
{
	if (c == 'c' || c == '%' || c == 's' || c == 'i' || c == 'd' || c == 'x' || c == 'X'|| c == 'u')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		len_cont;
	int		i;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && val_format(str[i + 1]))
		{
			len_cont = print_cont(str[i +1], arg);
			i++;
		}
		else
			len_cont = ft_print_char(str[i]);
		if (len_cont < 0)
			return (-1);
		else
			len += len_cont;
		i++;
	}
	va_end(arg);
	return (len);
}

#include <stdio.h>

int main (void)
{
	int	c;

	c = -15;
	ft_printf("%x", c);
	printf("\n");
	printf("%x",c);
}
