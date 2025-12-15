/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:44:21 by rarriola          #+#    #+#             */
/*   Updated: 2025/12/15 15:19:30 by rarriola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	flags(va_list *args, char flags);
int	printfchar(char c);
int	printfstr(char *s);
int	printfptr(void *p);
int	printfnbr(long long n);
int	print_hex(unsigned long n, int uppercase);

#endif