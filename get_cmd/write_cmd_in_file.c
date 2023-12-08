/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cmd_in_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:00:04 by pudry             #+#    #+#             */
/*   Updated: 2023/12/08 09:18:57 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static int	ft_is_redir(char *s)
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
			return (2);
		else if (s[2] != '<')
			return (2);
	}
	return (0);
}

static void	ft_put_redir_in_file(char **array, int itype, int i, int fd)
{
	int	j;

	if (itype == 2)
		j = 1;
	else
		j = -1;
	while (i >= 0 && array[i] && !(array[i][0] == '|' && array[i][1] == '\0'))
	{
		if (ft_is_redir(array[i]) == itype)
		{
			ft_putstr_fd(array[i], fd);
			ft_putstr_fd(" ", fd);
			ft_putstr_fd(array[i + 1], fd);
			ft_putstr_fd("\n", fd);
			if (j > 0)
				i += j;
		}
		i += j;
	}
}

static void	ft_put_cmd_in_file(char **array, int i, int fd)
{
	int	j;
	int	k;

	k = 0;
	ft_put_redir_in_file(array, 2, i, fd);
	while (array[i] && array[i][0] != '|')
	{
		if (array[i] && ft_is_redir(array[i]) != 0)
			i += 2;
		else
		{
			if (!array[i])
				break ;
			if (k != 0)
				ft_putstr_fd(" ", fd);
			ft_putstr_fd(array[i], fd);
			i ++;
			k ++;
		}
	}
	if (k)
		ft_putchar_fd('\n', fd);
	j = i - 1;
	ft_put_redir_in_file(array, 1, j, fd);
}

void	ft_put_data(char **array, int fd)
{
	int		i;

	i = 0;
	while (array && array[i])
	{
		ft_put_cmd_in_file(array, i, fd);
		while (array[i] && !(array[i][0] == '|' && array[i][1] == '\0'))
		{
			array[i] = ft_free_str(array[i]);
			i ++;
		}
		if (!array[i])
			break ;
		array[i] = ft_free_str(array[i]);
		i ++;
	}
	array = ft_free_ptr_ptr(array);
	close(fd);
	exit(0);
}

void	write_cmd_in_file(char *scmd, int fd)
{
	char	**array;
	int		i;

	array = ft_split_minishell(scmd);
	scmd = ft_free_str(scmd);
	if (!array)
		ft_error_int(12, 1, NULL, NULL);
	i = ft_check_syntax(array);
	if (i == 0)
		ft_error_int(201, 1, array, NULL);
	else if (i == 150)
		ft_error_int(150, 1, array, NULL);
	if (!array)
		ft_error_int(201, 1, array, NULL);
	ft_put_data(array, fd);
}
