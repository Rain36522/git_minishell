/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:10:29 by pudry             #+#    #+#             */
/*   Updated: 2023/11/25 20:42:15 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static int	ft_check_redir_pipe(char *array)
{
	if (ft_strncmp(array, "<<", 3) == 0)
		return (1);
	else if (ft_strncmp(array, ">>", 3) == 0)
		return (2);
	else if (array[1] == '\0' && array[0] == '<')
		return (3);
	else if (array[1] == '\0' && array[0] == '>')
		return (4);
	else if (array[1] == '\0' && array[0] == '|')
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
		return (ft_error_int(201, 0, array, NULL));
	while (array[i])
	{
		j = ft_check_redir_pipe(array[i]);
		if (j != 0)
		{
			k = ft_check_redir_pipe(array[i + 1]);
			if (k != 0 && j == 5 && k == 5)
				return (ft_error_int(201, 0, array, NULL));
			else if (array[i] + 1 == NULL)
				return (ft_error_int(201, 0, array, NULL));
		}
		i ++;
	}
	return (1);
}
