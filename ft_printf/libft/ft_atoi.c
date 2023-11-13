/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:38:51 by pudry             #+#    #+#             */
/*   Updated: 2023/10/12 11:14:34 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

static int	char_to_int(char *str)
{
	int	ivalue;

	ivalue = 0;
	while (*str >= 48 && *str <= 57)
	{
		ivalue = ivalue * 10 + (*str - 48);
		++ str;
	}
	return (ivalue);
}
/*This function return a number with  the sign + or -.
 * They took the information by the pointer given.
 * After that the charact are convert to an int value
 * and returned.*/

int	ft_atoi(char *str)
{
	int		iminus;
	int		ivalue;

	ivalue = 0;
	iminus = 1;
	if (!(*str))
		return (0);
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str ++;
	if (*str == '-')
		iminus *= -1;
	if (*str == '+' || *str == '-')
		++ str;
	if (*str >= '0' && *str <= '9')
		ivalue = char_to_int(str) * iminus;
	return (ivalue);
}
/*
int main(void)
{
	char *ptr = "";

	printf("%d \n", ft_atoi(ptr));
	return (0);
}
*/
