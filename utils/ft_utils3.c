/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:33:17 by pudry             #+#    #+#             */
/*   Updated: 2023/12/03 17:39:52 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	ft_cnt_dbl_redir_str(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
			j ++;
		str ++;
	}
	return (j);
}

char	**ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (NULL);
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	return (NULL);
}

void	ft_print_pipe_out(int fd_in)
{
	int		i;
	int		j;
	char	buf[BUFFER_SIZE + 1];

	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE)
	{
		i = read(fd_in, buf, BUFFER_SIZE);
		if (i < 0)
			break ;
		write(1, buf, i);
		j = 0;
		while (j <= BUFFER_SIZE && i == BUFFER_SIZE)
			buf[j++] = '\0';
	}
	if (i < 0)
		ft_error_int(23, 0, NULL, NULL);
}

t_acmd	*ft_util_add_pipe(t_acmd *acmd_data)
{
	int	fd[2];

	if (pipe(fd) < 0)
	{
		free(acmd_data);
		ft_error_ptr(9, 1, NULL, NULL);
	}
	acmd_data->fd_pipe[0] = fd[0];
	acmd_data->fd_pipe[1] = fd[1];
	return (acmd_data);
}

// This function replace the array contening the cmd
// by an string contening the cmd
// The ft free the array.
// The ft return Null case error
char	*ft_acmd_to_scmd(char **acmd)
{
	int		i;
	char	*scmd;

	if (!acmd || ! *acmd)
		return (NULL);
	i = 1;
	scmd = acmd[0];
	while (acmd[i] && scmd)
	{
		scmd = ft_strjoin(scmd, " ");
		if (scmd)
			scmd = ft_strjoin_free(scmd, acmd[i ++]);
	}
	while (acmd[i])
		free(acmd[i ++]);
	free(acmd);
	return (scmd);
}
