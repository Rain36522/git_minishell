/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:44:10 by pudry             #+#    #+#             */
/*   Updated: 2023/10/18 09:23:17 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrprct(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '%')
		ft_putchar_fd(s[i ++], 1);
	return (i);
}

int	ft_putunsigned(unsigned int n)
{
	int	i;

	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	ft_putunsign_int(n);
	while (n > 0)
	{
		i ++;
		n /= 10;
	}
	return (i);
}

int	ft_putnbr_int(int n)
{
	int		i;
	long	nbr;

	nbr = n;
	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	ft_putnbr_fd(n, 1);
	if (nbr < 0)
	{
		nbr *= -1;
		i ++;
	}
	while (nbr > 0)
	{
		i ++;
		nbr /= 10;
	}
	return (i);
}
