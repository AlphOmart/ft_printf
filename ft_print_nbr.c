/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:53:01 by mwubneh           #+#    #+#             */
/*   Updated: 2023/01/16 17:12:33 by mwubneh          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putnbr(int64_t nbr)
{
	int		i;
	char	c;

	i = 0;
	if (nbr < 0)
	{
		i += write (1, "-", 1);
		nbr *= -1;
	}
	if (10 <= nbr)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		i += write(1, &c, 1);
	}
	return (i);
}

int	ft_print_point(va_list arg)
{
	write(1, "0x", 2);
	return (ft_putnbr_p(va_arg(arg, unsigned long long),
			"0123456789abcdef") + 2);
}
