/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:44:46 by pudry             #+#    #+#             */
/*   Updated: 2023/11/14 14:09:45 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_replace_line(char *prompt, char *s2)
{
	ft_printf("\r");
	ft_printf("\033[2K");
	ft_printf("%s%s", prompt, s2);
}

char	*ft_skip_space_quotes(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\'' || *str == '\"')
	{
		if (*str == '\'')
		{
			while (*str && *str != '\'')
				str ++;
		}
		else if (*str == '\"')
		{
			while (*str && *str != '\"')
				str ++;
		}
		str ++;
	}
	return (str);
}
