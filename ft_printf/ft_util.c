/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:17:11 by pudry             #+#    #+#             */
/*   Updated: 2023/10/18 08:59:57 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cntarg(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i +1] != '%')
			j ++;
		else if (str[i] == '%' && str[i + 1] == '%')
			i ++;
		i ++;
	}
	return (j);
}

char	*ft_print_str(char *s)
{
	while (*s != '\0' && *s != '%')
	{
		ft_putchar_fd(*s, 1);
		s ++;
	}
	return (s);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (s[i])
	{
		i += ft_putchar(s[i]);
	}
	return (i);
}

int	ft_put_var(va_list va_lst, char *s)
{
	if (*s == '%')
	{
		if (s[1] == 'c')
			return (ft_putchar(va_arg(va_lst, int)));
		else if (s[1] == 's')
			return (ft_putstr(va_arg(va_lst, char *)));
		else if (s[1] == 'p')
			return (ft_putptr(va_arg(va_lst, void *)));
		else if (s[1] == 'i' || s[1] == 'd')
			return (ft_putnbr_int(va_arg(va_lst, int)));
		else if (s[1] == 'u')
			return (ft_putunsigned(va_arg(va_lst, unsigned int)));
		else if (s[1] == 'x')
			return (ft_putnbrhexdwn(va_arg(va_lst, unsigned int)));
		else if (s[1] == 'X')
			return (ft_putnbrhexup(va_arg(va_lst, unsigned int)));
		else if (s[1] == '%')
		{
			return (ft_putchar('%'));
		}
	}
	return (0);
}
