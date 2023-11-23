/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cmd_in_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:00:04 by pudry             #+#    #+#             */
/*   Updated: 2023/11/23 16:04:48 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static int ft_is_redir(char *s)
{
	if (s[0] == '>')
	{
		if (s[1] != '>')
			return (1);
		else if (s[2] != '>')
			return (1);
	}
	else if (s[0] == '<')
	{
		if (s[1] != '<')
			return (1);
		else if (s[2] != '<')
			return (1);
	}
	return (0);
}

static void	ft_put_cmd_in_file(char **array, int i, int fd)
{
	while (array[i] && !(array[i][0] == '|' && array[i][1] == '\0'))
	{
		while (ft_is_redir(array[i]) == 1)
			i += 2;
		if (!array[i])
			break;
		ft_putstr_fd(array[i], fd);
		ft_putstr_fd(" ", fd);
		i ++;
	}
	ft_putstr_fd("\n", fd);
	while (i > 0)
	{
		i --;
		if (ft_is_redir(array[i]) == 1)
		{
			ft_putstr_fd(array[i ++], fd);
			ft_putstr_fd(array[i], fd);
			ft_putstr_fd("\n", fd);
			i -= 1;
		}
	}
}

static void	ft_put_data(char **array, int fd)
{
	int		i;

	i = 0;
	ft_put_array(array);
	while (array && array[i])
	{
		ft_put_cmd_in_file(array, i, fd);
		while (array[i] && !(array[i][0] == '|' && array[i][1] == '\0'))
		{
			free(array[i]);
			i ++;
		}
		if (!array[i])
			break;
		free(array[i]);
		i ++;
	}
	free(array);
	close(fd);
	//exit(0);
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