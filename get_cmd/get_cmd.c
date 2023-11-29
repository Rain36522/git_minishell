/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:00:04 by pudry             #+#    #+#             */
/*   Updated: 2023/11/28 15:05:31 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_incmd	*error_and_redir_lst(char *scmd)
{
	t_incmd	*lst;
	char	**array;

	if (!scmd)
		ft_error_int(0, 1, NULL, scmd);
	if (! *scmd)
		return (NULL);
	add_history(scmd);
	if (!(ft_str_end_quotes(scmd, 0) == 0 && ft_cnt_dbl_redir_str(scmd) > 0))
		return (NULL);
	array = ft_split_minishell(scmd);
	if (!array)
		ft_error_int(12, 1, NULL, scmd);
	lst = ft_make_lst(array);
	ft_free_array(array);
	return (lst);
}

void	ft_double_input_redir(int *fd, char *scmd, t_incmd *lst)
{
	char	**array;

	array = ft_split_minishell(scmd);
	free(scmd);
	if (!array)
		ft_error_int(12, 1, NULL, NULL);
	if (ft_check_syntax(array) == 0)
		exit(201);
	if (!array)
		ft_error_int(12, 1, NULL, NULL);
	array = ft_replace_redir(lst, array);
	ft_write_file(lst);
	if (!array)
		ft_error_int(12, 1, NULL, NULL);
	ft_put_data(array, fd[1]);
}

void	ft_open_quotes_cmd(int *fd, char *scmd)
{
	int		i;
	char	*ptr2;

	i = ft_quotes(scmd, 0);
	while (i != 0 && scmd)
	{
		scmd = ft_strjoin_free(scmd, "\n");
		ptr2 = readline("> ");
		i = ft_quotes(ptr2, i);
		scmd = ft_strjoin_free(scmd, ptr2);
		free(ptr2);
	}
	if (!scmd)
		ft_error_int(12, 1, NULL, NULL);
	if (ft_cnt_dbl_redir_str(scmd) > 0)
		ft_error_int(201, 1, NULL, scmd);
	else
		write_cmd_in_file(scmd, fd[1]);
}

static void	ft_cmd_type(char *scmd, int *fd, t_incmd *lst)
{
	if (ft_str_end_quotes(scmd, 0) == 0)
		add_history(scmd);
	if (lst)
		ft_double_input_redir(fd, scmd, lst);
	else if (ft_cnt_dbl_redir_str(scmd) > 0)
		ft_error_int(201, 1, NULL, scmd);
	else if (ft_str_end_quotes(scmd, 0) != 0)
		ft_open_quotes_cmd(fd, scmd);
	else
		write_cmd_in_file(scmd, fd[1]);
}

t_acmd	*get_cmd(char *prompt)
{
	pid_t	pid;
	int		fd[2];
	char	*scmd;
	int		istatus;
	t_incmd	*lst;

	scmd = readline(prompt);
	if (pipe(fd) == -1)
		return (ft_error_ptr(32, 1, NULL, prompt));
	lst = error_and_redir_lst(scmd);
	pid = fork();
	if (pid < 0)
		return (ft_error_ptr(10, 1, NULL, prompt));
	else if (pid == 0)
		ft_cmd_type(scmd, fd, lst);
	else
	{
		close(fd[1]);
		waitpid(pid, &istatus, 0);
		if (WEXITSTATUS(istatus) != 0)
			return (ft_error_child(WEXITSTATUS(istatus), NULL, NULL, NULL));
		return (ft_file_to_array(fd[0]));
	}
	return (NULL);
}
