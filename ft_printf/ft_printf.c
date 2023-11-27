/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:36:58 by pudry             #+#    #+#             */
/*   Updated: 2023/11/25 15:29:33 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include  <stdio.h>

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	int		isize;
	char	*s;
	va_list	va_lst;

	(void) i;
	s = (char *)str;
	i = ft_cntarg(s);
	isize = 0;
	va_start(va_lst, str);
	j = ft_putstrprct(s);
	s += j;
	isize += j;
	while (*s)
	{
		isize += ft_put_var(va_lst, s);
		s += 2;
		j = ft_putstrprct(s);
		isize += j;
			s += j;
	}
	va_end(va_lst);
	return (isize);
}
/*
int	main(void)
{
	int		i;
	int		j;

	i = ft_printf("%i", -10);
	j = printf("%i", -10);
	printf("my : %i, original %i\n", i, j );
	return (0);
}
*/