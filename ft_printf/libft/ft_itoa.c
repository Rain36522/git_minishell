/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:50:51 by pudry             #+#    #+#             */
/*   Updated: 2023/10/16 12:42:16 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_char(long i)
{
	int	j;

	j = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		j ++;
		i /= 10;
	}
	return (j);
}

static void	ft_int_to_str(char *ptr, int i, long n)
{
	while (n > 0)
	{
		ptr[i--] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	nbr;
	int		imin;
	int		isize;

	nbr = n;
	imin = 0;
	if (nbr < 0)
	{
		imin = 1;
		nbr *= -1;
	}
	isize = ft_size_char(nbr);
	ptr = (char *) malloc(isize + imin + 1);
	if (!ptr)
		return (NULL);
	ptr[isize + imin] = '\0';
	if (imin == 1)
		ptr[0] = '-';
	if (nbr <= 9 && imin == 0)
		ptr[0] = nbr + '0';
	else
		ft_int_to_str(ptr, isize + imin - 1, nbr);
	return (ptr);
}
/*
int	main(void)
{
	int	i = 928795221;
	printf("int : %s\n", ft_itoa(i));
	return (0);
}
*/