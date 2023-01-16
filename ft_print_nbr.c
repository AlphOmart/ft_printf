/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:53:01 by mwubneh           #+#    #+#             */
/*   Updated: 2023/01/16 18:29:01 by mwubneh          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdbool.h>

int	ft_putnbr_p(unsigned long long nbr, char *base)
{
	unsigned long long		len_base;
	int						c;

	c = 0;
	len_base = ft_strlen(base);
	if (nbr < 0)
	{
		if (len_base == 10)
			c += write (1, "-", 1);
		nbr *= -1;
	}
	if (len_base <= nbr)
	{
		c += ft_putnbr_p(nbr / len_base, base);
		c += ft_putnbr_p(nbr % len_base, base);
	}
	else
		c += write(1, &base[nbr], 1);
	return (c);
}

// int	ft_putnbr(int64_t nbr)
// {
// 	int		a;
// 	int		i;
// 	char	c;

// 	i = 0;
// 	if (nbr < 0)
// 	{
// 		i = write (1, "-", 1);
// 		if (i == -1)
// 			return (-1);
// 		nbr *= -1;
// 	}
// 	if (10 <= nbr)
// 	{
// 		i += ft_putnbr(nbr / 10);
// 		i += ft_putnbr(nbr % 10);
// 	}
// 	else
// 	{
// 		c = nbr + '0';
// 		a = i;
// 		i += write(1, &c, 1);
// 		if (a <= i)
// 			return (-1);
// 	}
// 	return (i);
// }

size_t	ft_putnbr(int64_t nbr)
{
	bool	is_neg;
	char	number_str[12];
	char	*cursor;

	if (nbr == 0)
		return (ft_print_str("0"));
	is_neg = nbr < 0;
	if (is_neg)
		nbr = -nbr;
	number_str[11] = '\0';
	cursor = number_str + 10;
	while (nbr != 0)
	{
		*cursor-- = nbr % 10 + '0';
		nbr /= 10;
	}
	if (is_neg)
		*cursor-- = '-';
	return (ft_print_str(cursor + 1));
}

size_t	ft_putnbr_hexa(unsigned int nbr, char *base)
{
	char	number_str[SIZE];
	char	*cursor;

	if (nbr == 0)
		return (ft_print_str("0"));
	number_str[SIZE - 1] = '\0';
	cursor = number_str + SIZE - 2;
	while (nbr != 0)
	{
		*cursor-- = base[nbr % 16];
		nbr /= 16;
	}
	return (ft_print_str(cursor + 1));
}

int	ft_print_point(va_list arg)
{
	size_t	ft_putnbr_p_return;

	if (write(1, "0x", 2) == -1)
		return (-1);
	ft_putnbr_p_return = ft_putnbr_p(va_arg(arg, unsigned long long),
			"0123456789abcdef");
	if (ft_putnbr_p_return == -1)
		return (-1);
	return (ft_putnbr_p_return + 2);
}
