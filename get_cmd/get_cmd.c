/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:00:04 by pudry             #+#    #+#             */
/*   Updated: 2023/12/08 08:45:24 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static void	ft_double_input_redir(int *fd, char *scmd, \
											t_incmd *lst, t_data *data)
{
	char	**array;

	array = ft_split_minishell(scmd);
	scmd = ft_free_str(scmd);
	if (!array)
		ft_error_int(12, 1, NULL, NULL);
	if (ft_check_syntax(array) == 0)
		exit(201);
	else if (ft_check_syntax(array) == 150)
		exit(150);
	if (!array)
		ft_error_int(12, 1, NULL, NULL);
	array = ft_replace_redir(lst, array);
	ft_write_file(lst, array, data);
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
		if (!ptr2)
			ft_error_int(1, 1, NULL, scmd);
		i = ft_quotes(ptr2, i);
		scmd = ft_strjoin_free(scmd, ptr2);
		ptr2 = ft_free_str(ptr2);
	}
	if (!scmd)
		ft_error_int(12, 1, NULL, NULL);
	if (ft_cnt_dbl_redir_str(scmd) > 0)
		ft_error_int(201, 1, NULL, scmd);
	else
		write_cmd_in_file(scmd, fd[1]);
}

static void	ft_cmd_type(char *scmd, int *fd, t_incmd *lst, t_data *data)
{
	signal(SIGINT, child_signal);
	if (ft_str_end_quotes(scmd, 0) == 0)
		add_history(scmd);
	if (lst)
		ft_double_input_redir(fd, scmd, lst, data);
	else if (ft_cnt_dbl_redir_str(scmd) > 0)
		ft_error_int(201, 1, NULL, scmd);
	else if (ft_str_end_quotes(scmd, 0) != 0)
		ft_open_quotes_cmd(fd, scmd);
	else
		write_cmd_in_file(scmd, fd[1]);
}

static t_acmd	*get_cmd_parent(int *fd, t_incmd *lst, t_data *data)
{
	t_incmd	*lst_next;

	while (lst)
	{
		lst_next = lst->next;
		close(lst->fd[1]);
		free(lst->read_fd);
		lst->wrd = ft_free_str(lst->wrd);
		free(lst);
		lst = lst_next;
	}
	return (ft_file_to_array(fd[0], fd[1], data));
}

t_acmd	*get_cmd(char *prompt, t_data *data)
{
	int		fd[2];
	char	*scmd;
	t_incmd	*lst;

	scmd = readline(prompt);
	if (!input_error(scmd))
		return (NULL);
	if (pipe(fd) == -1)
		return (ft_error_ptr(32, 1, NULL, prompt));
	lst = redir_lst(scmd);
	data->pid = fork();
	if (data->pid < 0)
		return (ft_error_ptr(10, 1, NULL, prompt));
	else if (data->pid == 0)
		ft_cmd_type(scmd, fd, lst, data);
	else
	{
		waitpid(data->pid, &data->iexit, 0);
		if (WEXITSTATUS(data->iexit) != 0)
			return (ft_error_get_cmd(WEXITSTATUS(data->iexit), \
										data->env, NULL, NULL));
		return (get_cmd_parent(fd, lst, data));
	}
	return (NULL);
}
