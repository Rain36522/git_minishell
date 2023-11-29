/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:10:29 by pudry             #+#    #+#             */
/*   Updated: 2023/11/29 12:41:30 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static int	ft_check_redir_pipe(char *str)
{
	if (!str || ! *str)
		return (0);
	if (ft_strncmp(str, "<<", 3) == 0)
		return (1);
	else if (ft_strncmp(str, ">>", 3) == 0)
		return (2);
	else if (str[1] == '\0' && str[0] == '<')
		return (3);
	else if (str[1] == '\0' && str[0] == '>')
		return (4);
	else if (str[1] == '\0' && str[0] == '|')
		return (5);
	else
		return (0);
}

int	ft_check_syntax(char **array)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (array[0][0] == '|' || array[0][1] == '|')
		return (0);
	while (array[i])
	{
		if (array[i][0] == '|' && array[i][1] == '|')
			return (0);
		j = ft_check_redir_pipe(array[i]);
		if (j != 0)
		{
			k = ft_check_redir_pipe(array[i + 1]);
			if (k != 0 && j == 5 && k == 5)
				return (0);
			else if (array[i + 1] == NULL)
				return (0);
			ft_printf("str : %s, str1 : %s\n", array[i], array[i + 1]);
		}
		i ++;
	}
	return (1);
}
