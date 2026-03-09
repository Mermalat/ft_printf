/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:33:44 by memalli           #+#    #+#             */
/*   Updated: 2026/03/02 22:33:46 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int n)
{
	int	len;
	int	tmp;

	len = 0;
	if (n == -2147483648)
	{
		tmp = ft_putstr_len("-2147483648");
		if (tmp == -1)
			return (-1);
		return (tmp);
	}
	if (n < 0)
	{
		tmp = ft_putchar_len('-');
		if (tmp == -1)
			return (-1);
		len += tmp;
		n = -n;
	}
	if (n > 9)
	{
		tmp = ft_putnbr_len(n / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	tmp = ft_putchar_len((n % 10) + '0');
	if (tmp == -1)
		return (-1);
	return (len + tmp);
}

int	ft_putunbr_len(unsigned int n)
{
	int	len;
	int	tmp;

	len = 0;
	if (n > 9)
	{
		tmp = ft_putunbr_len(n / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	tmp = ft_putchar_len((n % 10) + '0');
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}
