/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:10:29 by pudry             #+#    #+#             */
/*   Updated: 2023/12/08 09:18:46 by pudry            ###   ########.fr       */
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

static int	ft_check_multiple_redir(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '<' || str[i] == '>'))
		i ++;
	if (i >= 3)
		return (0);
	return (1);
}

int	ft_check_syntax(char **array)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (array[i])
	{
		if ((array[i][0] == '|' && array[i][1] == '|') || \
							!ft_check_multiple_redir(array[i]))
			return (0);
		j = ft_check_redir_pipe(array[i]);
		if (j != 0)
		{
			k = ft_check_redir_pipe(array[i + 1]);
			if ((k != 0 && j != 5) || (k == j && k == 5))
				return (0);
			else if (array[i + 1] == NULL)
				return (0);
		}
		i ++;
	}
	if (ft_check_redir_pipe(array[0]) > 0 && ft_check_redir_pipe(array[0]) < 5 \
				&& i == 2)
		return (150);
	return (1);
}
