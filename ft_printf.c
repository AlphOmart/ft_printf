/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:55:48 by mwubneh           #+#    #+#             */
/*   Updated: 2023/01/14 00:14:32 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_cont(char c, va_list arg)
{
	if (c == 'c')
		return (ft_print_char((char) va_arg(arg, int)));
	return (0);
}

int	val_format(char c)
{
	if (c == 'c')
		return (1);
	return (0);
}

int	ft_printf(char *str, ...)
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

int	main(void)
{
	ft_printf("%c%c", 'a', 'b');
	printf("\n");
	printf("%c%c", 'a', 'b');
	return (0);
}
