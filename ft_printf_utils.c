/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:38:31 by rarriola          #+#    #+#             */
/*   Updated: 2025/12/15 15:27:59 by rarriola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printfchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printfstr(char *s)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count);
}

int	print_hex(unsigned long n, int uppercase)
{
	char	*base;
	int		count;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += print_hex(n / 16, uppercase);
	write(1, &base[n % 16], 1);
	count++;
	return (count);
}

int	printfptr(void *p)
{
	int	count;

	if (!p)
	{
		count = 5;
		write(1, "(nil)", 5);
		return (count);
	}
	count = 2;
	write(1, "0x", 2);
	count += print_hex((unsigned long)p, 0);
	return (count);
}

int	printfnbr(long long n)
{
	int		c;

	c = 0;
	if (n == -2147483648)
	{
		c += write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		c += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		c += printfnbr(n / 10);
		c += printfchar((n % 10) + '0');
	}
	else
		c += printfchar(n + '0');
	return (c);
}
