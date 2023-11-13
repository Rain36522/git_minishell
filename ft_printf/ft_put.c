/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:00:45 by pudry             #+#    #+#             */
/*   Updated: 2023/10/18 09:01:20 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned long n, char *hex)
{
	if (n < 16)
		ft_putchar_fd(hex[n], 1);
	else
	{
		ft_puthex(n / 16, hex);
		ft_puthex(n % 16, hex);
	}
}

int	ft_putnbrhexdwn(unsigned long n)
{
	int		i;

	if (!n)
		return (ft_putchar('0'));
	ft_puthex(n, "0123456789abcdef");
	i = 0;
	while (n > 0)
	{
		i ++;
		n /= 16;
	}
	return (i);
}

int	ft_putnbrhexup(unsigned long n)
{
	int		i;

	if (!n)
		return (ft_putchar('0'));
	i = 0;
	ft_puthex(n, "0123456789ABCDEF");
	while (n > 0)
	{
		i ++;
		n /= 16;
	}
	return (i);
}

int	ft_putptr(void *mem)
{
	unsigned long		n;
	int					i;

	n = (unsigned long) mem;
	ft_putstr_fd("0x", 1);
	if (!n)
		return (2 + ft_putchar('0'));
	ft_putnbrhexdwn(n);
	i = 2;
	while (n > 0)
	{
		i ++;
		n /= 16;
	}
	return (i);
}

void	ft_putunsign_int(unsigned int n)
{
	if (n <= 9)
		ft_putchar_fd(n + '0', 1);
	else
	{
		ft_putunsign_int(n / 10);
		ft_putunsign_int(n % 10);
	}
}
