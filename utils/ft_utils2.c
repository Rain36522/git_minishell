/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:01:00 by pudry             #+#    #+#             */
/*   Updated: 2023/11/22 18:05:57 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	ft_check_is_quote(char c, int i)
{
	if (c  == '\"' && i == 2)
		i = 0;
	else if (c == '\"' && i == 0)
		i = 2;
	else if (c == '\'' && i == 0)
		i = 1;
	else if (c == '\'' && i == 1)
		i = 0;
	return (i);		
}

int	ft_str_end_quotes(char *str, int i)
{
	i = 0;
	while (*str)
	{
		i = ft_check_is_quote(*str, i);
		str ++;
	}
	return (i);
}