/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:55:16 by rarriola          #+#    #+#             */
/*   Updated: 2025/12/15 15:19:28 by rarriola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags(va_list *args, char flags)
{
	int	count;

	count = 0;
	if (flags == 'c')
		count += printfchar(va_arg(*args, int));
	else if (flags == 's')
		count += printfstr(va_arg(*args, char *));
	else if (flags == 'p')
		count += printfptr(va_arg(*args, void *));
	else if (flags == 'd' || flags == 'i')
		count += printfnbr(va_arg(*args, int));
	else if (flags == 'u')
		count += printfnbr(va_arg(*args, unsigned int));
	else if (flags == 'x')
		count += print_hex((long)va_arg(*args, unsigned int), 0);
	else if (flags == 'X')
		count += print_hex((long)va_arg(*args, unsigned int), 1);
	else if (flags == '%')
		count += printfchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += flags(&args, *format);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
