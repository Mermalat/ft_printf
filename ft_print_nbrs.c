/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:25:00 by merma             #+#    #+#             */
/*   Updated: 2026/02/25 19:27:54 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putstr_len("-2147483648");
	}
	else
	{
		if (n < 0)
		{
			len += ft_putchar_len('-');
			n = -n;
		}
		if (n > 9)
		{
			len += ft_putnbr_len(n / 10);
		}
		len += ft_putchar_len((n % 10) + '0');
	}
	return (len);
}

int	ft_putunbr_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putunbr_len(n / 10);
	len += ft_putchar_len((n % 10) + '0');
	return (len);
}
