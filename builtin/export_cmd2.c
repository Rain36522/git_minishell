/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:57:36 by pudry             #+#    #+#             */
/*   Updated: 2023/12/01 11:56:32 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header_builtin.h"

static char	*ft_put_to_egal(char *str)
{
	while (*str && *str != '=')
	{
		ft_putchar(*str);
		str ++;
	}
	if (*str == '=')
	{
		ft_putchar('=');
		str ++;
	}
	return (str);
}

void	ft_put_export(char **array)
{
	int		i;
	char	*ptr;

	i = 0;
	while (array[i])
	{
		ft_printf("declare -x ");
		ptr = ft_put_to_egal(array[i]);
		ft_printf("\"%s\"\n", ptr);
	}
}
