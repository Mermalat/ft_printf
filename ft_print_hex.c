/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:33:49 by memalli           #+#    #+#             */
/*   Updated: 2026/03/02 22:33:52 by memalli          ###   ########.fr       */
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
