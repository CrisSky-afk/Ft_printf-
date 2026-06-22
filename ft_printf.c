/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris <cris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:28:57 by csuomins          #+#    #+#             */
/*   Updated: 2026/06/22 15:56:33 by cris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_src(char format, va_list arg)
{
	int	ret;

	ret = 0;
	if (format == 'c')
		ret += ft_putchar(va_arg(arg, int));
	else if (format == 's')
		ret += ft_putstr(va_arg(arg, char *));
	else if (format == 'p')
		ret += ft_pointer((unsigned long)va_arg(arg, void *));
	else if (format == 'd' || format == 'i')
		ret += ft_putnbr(va_arg(arg, int));
	else if (format == 'u')
		ret += ft_putnbruns(va_arg(arg, unsigned int));
	else if (format == 'x')
		ret += ft_puthex(16, "0123456789abcdef", va_arg(arg, unsigned int));
	else if (format == 'X')
		ret += ft_puthex(16, "0123456789ABCDEF", va_arg(arg, unsigned int));
	else if (format == '%')
		ret += ft_putchar('%');
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	size_t		i;
	int			ret;
	va_list		arg;

	va_start(arg, format);
	i = 0;
	ret = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ret += ft_src(format[i + 1], arg);
			i += 2;
		}
		else
		{
			ret += ft_putchar(format[i]);
			i++;
		}
	}
	va_end (arg);
	return (ret);
}
