/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:48:32 by pudry             #+#    #+#             */
/*   Updated: 2023/11/22 17:58:35 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*
 *	Check if single or double quotes aren't close
 *	return != 0 if quotes aren't closed
 *	2 = double
 *	1 = simple
 */
static int	ft_quotes(char *str, int istatus)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' && istatus == 2)
			istatus = 0;
		else if (str[i] == '\"' && istatus == 0)
			istatus = 2;
		else if (str[i] == '\'' && istatus == 1)
			istatus = 0;
		else if (str[i] == '\'' && istatus == 0)
			istatus = 1;
		if (str[i] == '|' && istatus == 0)
			return (0);
		i++;
	}
	return (istatus);
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

void	ft_put_array_file(char **a, int fd)
{
	int	i;

	i = 0;
	while (a[i])
	{
		ft_putstr_fd(a[i], fd);
		i ++;
	}
	;
}

void	ft_make_cmd_quote(char *scmd, int *fd)
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
	
}

static char	**ft_make_simple_cmd(char *scmd)
{
	char	**array;

	array = ft_split_minishell(scmd);
	free(scmd);
	if (!array)
		ft_error_array(12, 1, NULL, NULL);
	if (ft_check_syntax(array) == 0)
		return (NULL);
	return (array);
}

char	**get_cmd(char *prompt)
{
	char	*scmd;
	char	**array;
	pid_t	*pid;
	int		*fd_read;

	scmd = readline(prompt);
	if (!scmd)
		return (ft_error_array(12, 1, NULL, NULL));
	add_history(scmd);
	if (pipe(fd_read) < 0)
		ft_error_array(32, 1, NULL, scmd);
	pid = fork();
	if (pid < 0)
		return (ft_error_array(10, 1, NULL, scmd));
	else if (pid == 0)
	{
		if (ft_check_dbl_redi_str(scmd) == 1 && ft_quotes(scmd, 0) == 0)
			ft_make_dbl_redir(scmd);
		else if (ft_quotes(scmd, 0) == 0)
			ft_make_simple_cmd(scmd);
		else
			ft_make_cmd_quote(scmd);
	}
	else
		ft_recup_data()
}
