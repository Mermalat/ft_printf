/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:25:00 by merma             #+#    #+#             */
/*   Updated: 2026/02/17 23:25:00 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_len(unsigned int n, char format)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex_len(n / 16, format);
	if (format == 'x')
		len += ft_putchar_len("0123456789abcdef"[n % 16]);
	else if (format == 'X')
		len += ft_putchar_len("0123456789ABCDEF"[n % 16]);
	return (len);
}

static int	ft_putaddr_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_putaddr_len(n / 16);
	len += ft_putchar_len("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_putptr_len(void *ptr)
{
	if (!ptr)
		return (ft_putstr_len("(nil)"));
	return (ft_putstr_len("0x") + ft_putaddr_len((unsigned long)ptr));
}
