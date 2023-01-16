/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:22:24 by mwubneh           #+#    #+#             */
/*   Updated: 2023/01/16 17:12:51 by mwubneh          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr(int64_t nbr);
int	ft_abs(int nbr);
int	ft_strlen(char *str);
int	ft_putnbr_p(unsigned long long nbr, char *base);
int	ft_print_point(va_list arg);
int	ft_print_str(const char *str);
int	ft_print_char(char c);
int	ft_print_cont(char c, va_list arg);
int	val_format(char c);
int	ft_printf(const char *str, ...);

#endif
