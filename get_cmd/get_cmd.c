/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:00:04 by pudry             #+#    #+#             */
/*   Updated: 2023/11/22 20:24:39 by pudry            ###   ########.fr       */
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
		ft_error_array(12, 1, NULL, NULL);
	ft_put_cmd_in_file(scmd, fd[1]);
}

void	ft_double_input_redir(int *fd, char *scmd)
{
	char	**array;
	t_incmd	*lst;

	array = ft_split_minishell(array);
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
	ft_put_cmd_in_file(scmd, fd[1]);		
}


char	**get_cmd(char *prompt);