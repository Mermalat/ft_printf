/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memalli <memalli@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:33:58 by memalli           #+#    #+#             */
/*   Updated: 2026/03/02 22:34:00 by memalli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

int		ft_putchar_len(char c);
int		ft_putstr_len(char *s);
int		ft_putnbr_len(int n);
int		ft_putunbr_len(unsigned int n);
int		ft_puthex_len(unsigned int n, char format);
int		ft_putptr_len(void *ptr);

#endif
