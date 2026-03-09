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
	int	tmp;

	len = 0;
	if (n >= 16)
	{
		tmp = ft_puthex_len(n / 16, format);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (format == 'x')
		tmp = ft_putchar_len("0123456789abcdef"[n % 16]);
	else
		tmp = ft_putchar_len("0123456789ABCDEF"[n % 16]);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}

static int	ft_putaddr_len(unsigned long n)
{
	int	len;
	int	tmp;

	len = 0;
	if (n >= 16)
	{
		tmp = ft_putaddr_len(n / 16);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	tmp = ft_putchar_len("0123456789abcdef"[n % 16]);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}

int	ft_putptr_len(void *ptr)
{
	int	len;
	int	tmp;

	if (!ptr)
		return (ft_putstr_len("(nil)"));
	len = ft_putstr_len("0x");
	if (len == -1)
		return (-1);
	tmp = ft_putaddr_len((unsigned long)ptr);
	if (tmp == -1)
		return (-1);
	return (len + tmp);
}
