/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cmd_in_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:00:04 by pudry             #+#    #+#             */
/*   Updated: 2023/11/23 12:40:23 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static void	ft_put_cmd_in_file(char **array, int fd)
{
	int		i;

	i = 0;
	while (array[i] && !(array[i][0] == '|' && array[i][1] == '\0'))
	{
		if (ft_strncmp(array[i], ">>", 3) == 0 || \
			(array[i][0] == '>' && array[i][1] == '\0'))
			i += 2;
		if (!array[i])
			break;
		ft_putstr_fd(array[i], fd);
		ft_putstr_fd("\n", fd);
	}
	while (i >= 0)
	{
		i --;
		if (ft_strncmp(array[i], ">>", 3) == 0 || \
			(array[i][0] == '>' && array[i][1] == '\0'))
		{
			ft_putstr_fd(array[i ++], fd);
			ft_putstr_fd(array[i ++], fd);
			ft_putstr_fd("\n", fd);
		}
	}
}

static void	ft_put_data(char **array, int fd)
{
	char	**mem_array;

	mem_array = array;
	while (array)
	{
		ft_put_cmd_in_file(array, fd);
		while (array && array[0][0] != '\n' && array[0][1] != '\0')
		{
			free(*array);
			array ++;
		}
		if (!array)
			break;
		free(*array);
		array ++;
	}
	free(mem_array);
	exit(0);
}

void	write_cmd_in_file(char *scmd, int fd)
{
	char	**array;
	int		i;

	array = ft_split_minishell(scmd);
	free(scmd);
	if (!array)
		ft_error_int(12, 1, NULL, NULL);	
	i = ft_check_syntax(array);
	if (i == 0)
		exit(201);
	array = from_quotes_to_wrds(array);
	if (!array)
		ft_error_int(12, 1, NULL, NULL);	
	ft_put_data(array, fd);
}