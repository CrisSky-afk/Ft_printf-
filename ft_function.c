/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris <cris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:45:07 by csuomins          #+#    #+#             */
/*   Updated: 2026/06/22 15:55:36 by cris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
		i += ft_putchar(str[i]);
	return (i);
}

int	ft_putnbr(int nb)
{
	long	number;
	int		ret;

	number = nb;
	ret = 0;
	if (number < 0)
	{
		ret += ft_putchar('-');
		number = -number;
	}
	if (number >= 10)
		ret += ft_putnbr(number / 10);
	ret += ft_putchar((number % 10) + '0');
	return (ret);
}
