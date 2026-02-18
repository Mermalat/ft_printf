/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merma <merma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:30:00 by merma             #+#    #+#             */
/*   Updated: 2026/02/17 23:30:00 by merma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	ft_ret;
	int	og_ret;

	printf("--- Char ---\n");
	ft_ret = ft_printf("ft: %c\n", 'A');
	og_ret = printf("og: %c\n", 'A');
	printf("ft_ret: %d, og_ret: %d\n", ft_ret, og_ret);

	printf("\n--- String ---\n");
	ft_ret = ft_printf("ft: %s\n", "Hello, World!");
	og_ret = printf("og: %s\n", "Hello, World!");
	printf("ft_ret: %d, og_ret: %d\n", ft_ret, og_ret);
	
	char *null_str = NULL;
	ft_ret = ft_printf("ft: %s\n", null_str);
	// Standard printf might crash or ANY behavior on NULL %s, but we test if it runs.
	// On Linux glibc it prints (null).
	// We will use a wrapper or just comment out the OG printf if it causes issues, 
	// but let's try with a variable first.
	og_ret = printf("og: %s\n", null_str);
	printf("ft_ret: %d, og_ret: %d\n", ft_ret, og_ret);

	printf("\n--- Pointer ---\n");
	int a = 42;
	ft_ret = ft_printf("ft: %p\n", &a);
	og_ret = printf("og: %p\n", &a);
	printf("ft_ret: %d, og_ret: %d\n", ft_ret, og_ret);

	ft_ret = ft_printf("ft: %p\n", NULL);
	og_ret = printf("og: %p\n", NULL);
	printf("ft_ret: %d, og_ret: %d\n", ft_ret, og_ret);

	printf("\n--- Decimal/Int ---\n");
	ft_ret = ft_printf("ft: %d, %i\n", 42, -42);
	og_ret = printf("og: %d, %i\n", 42, -42);
	printf("ft_ret: %d, og_ret: %d\n", ft_ret, og_ret);

	ft_ret = ft_printf("ft: %d\n", INT_MIN);
	og_ret = printf("og: %d\n", INT_MIN);
	printf("ft_ret: %d, og_ret: %d\n", ft_ret, og_ret);

	printf("\n--- Unsigned ---\n");
	ft_ret = ft_printf("ft: %u\n", 42);
	og_ret = printf("og: %u\n", 42);
	printf("ft_ret: %d, og_ret: %d\n", ft_ret, og_ret);
	
	ft_ret = ft_printf("ft: %u\n", -1);
	og_ret = printf("og: %u\n", -1);
	printf("ft_ret: %d, og_ret: %d\n", ft_ret, og_ret);

	printf("\n--- Hex ---\n");
	ft_ret = ft_printf("ft: %x %X\n", 255, 255);
	og_ret = printf("og: %x %X\n", 255, 255);
	printf("ft_ret: %d, og_ret: %d\n", ft_ret, og_ret);
	
	ft_ret = ft_printf("ft: %x\n", 0);
	og_ret = printf("og: %x\n", 0);
	printf("ft_ret: %d, og_ret: %d\n", ft_ret, og_ret);

	printf("\n--- Percent ---\n");
	ft_ret = ft_printf("ft: %%\n");
	og_ret = printf("og: %%\n");
	printf("ft_ret: %d, og_ret: %d\n", ft_ret, og_ret);
	
	return (0);
}
