/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:00:04 by pudry             #+#    #+#             */
/*   Updated: 2023/11/23 12:39:41 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_open_quotes_cmd(int *fd, char *scmd)
{
	int		i;
	char	*ptr;
	char	*ptr2;

	i = ft_quotes(scmd, 0);
	while (i != 0 && scmd)
	{
		scmd = ft_strjoin(scmd, "\n");
		ptr = scmd;
		ptr2 = readline("> ");
		i = ft_quotes(ptr2, i);
		scmd = ft_strjoin(ptr, ptr2);
		free(ptr);
		free(ptr2);
	}
	if (!scmd)
		ft_error_int(12, 1, NULL, NULL);
	write_cmd_in_file(scmd, fd[1]);
}

void	ft_double_input_redir(int *fd, char *scmd)
{
	char	**array;
	t_incmd	*lst;

	array = ft_split_minishell(scmd);
	if (!array)
		ft_error_int(12, 1, NULL, NULL);
	if (ft_check_syntax(array) == 0)
		exit(201);
	array = from_quotes_to_wrds(array);
	if (!array)
		ft_error_int(12, 1, NULL, NULL);
	lst = ft_make_lst(array);
	if (!lst)
		ft_error_int(12, 1, NULL, NULL);
	array = ft_replace_redir(lst, array);
	ft_write_file(lst);
	if (!array)
		ft_error_int(12, 1, NULL, NULL);
	write_cmd_in_file(scmd, fd[1]);		
}

static int	ft_check_dbl_redi_str(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (i == 0 && *str == '\"')
			i = 2;
		else if (i == 2 && *str == '\"')
			i = 0;
		else if (i == 0 && *str == '\'')
			i = 1;
		else if (i == 1 && *str == '\'')
			i = 0;
		else if (i == 0 && str[0] == '<' && str[1] == '<' && str[2] != '<')
			return (1);
		str ++;
	}
	return (0);
}

static void	ft_cmd_type(char *scmd, int *fd)
{
	if (!scmd || !*scmd)
		exit(0);
	else if (ft_quotes(scmd, 0) != 0 && ft_check_dbl_redi_str(scmd) == 1)
		ft_double_input_redir(fd, scmd);
	else if (ft_check_dbl_redi_str(scmd) == 1)
		ft_error_int(201, 1, NULL, scmd);
	else if (ft_quotes(scmd, 0) != 0)
		ft_open_quotes_cmd(fd, scmd);
	else
		write_cmd_in_file(scmd, fd[1]);
}

char	**get_cmd(char *prompt)
{
	pid_t	pid;
	int		fd[2];
	char	**array;
	int		istatus;
	char	*scmd;
	
	scmd = readline(prompt);
	if (pipe(fd) == -1)
		return (ft_error_array(32, 1, NULL, prompt));
	pid = fork();
	if (pid < 0)
		return (ft_error_array(10, 1, NULL, prompt));
	else if (pid != 0)
	{
		waitpid(pid, &istatus, 0);
		if (istatus != 0)
			return (ft_error_array(150, 1, NULL, prompt));
		return (array = ft_file_to_array(fd[0]));
	}
	else
		ft_cmd_type(scmd, fd);
	return (NULL);
}
