/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:10:29 by pudry             #+#    #+#             */
/*   Updated: 2023/11/22 19:09:38 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../Includes/minishell.h"

static int	ft_check_redir_pipe(char *array)
{
	if (ft_strncmp(array, "<<", 3) == 0)
		return (1);
	else if (ft_strncmp(array, ">>", 3) == 0)
		return (1);
	else if (array[1] == '\0'  && array[0] == '<')
		return (1);
	else if (array[1] == '\0'  && array[0] == '>')
		return (1);
	else if (array[1] == '\0'  && array[0] == '|')
		return (1);
	else
		return (0);
}

int	ft_check_syntax(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		if (ft_check_redir_pipe(array[i]) == 1)
		{
			if (ft_check_redir_pipe(array[i + 1]) == 1)
				return (ft_error_int(201, 0, array, NULL));
			else if (array[i] + 1 == NULL)
				return (ft_error_int(201, 0, array, NULL));
		}
		i ++;
	}
	return (1);
}