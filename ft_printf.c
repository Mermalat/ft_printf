/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:33:37 by memalli           #+#    #+#             */
/*   Updated: 2026/03/02 22:33:41 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_putchar_len(va_arg(args, int));
	else if (format == 's')
		print_length += ft_putstr_len(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_putptr_len(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_length += ft_putnbr_len(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_putunbr_len(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_puthex_len(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_putchar_len('%');
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			print_length += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			print_length += ft_putchar_len(format[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
