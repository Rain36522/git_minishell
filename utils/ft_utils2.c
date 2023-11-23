/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:01:00 by pudry             #+#    #+#             */
/*   Updated: 2023/11/23 12:27:43 by pudry            ###   ########.fr       */
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

int	ft_quotes(char *str, int istatus)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' && istatus == 2)
			istatus = 0;
		else if (str[i] == '\"' && istatus == 0)
			istatus = 2;
		else if (str[i] == '\'' && istatus == 1)
			istatus = 0;
		else if (str[i] == '\'' && istatus == 0)
			istatus = 1;
		if (str[i] == '|' && istatus == 0)
			return (0);
		i++;
	}
	return (istatus);
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