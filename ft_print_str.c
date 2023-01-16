/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:45:13 by mwubneh           #+#    #+#             */
/*   Updated: 2023/01/16 16:45:55 by mwubneh          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
