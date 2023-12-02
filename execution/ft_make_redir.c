/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:10:35 by pudry             #+#    #+#             */
/*   Updated: 2023/12/02 13:59:23 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_redir(int fd_in, int fd_out)
{
	char	buf[BUFFER_SIZE + 1];
	int		i;
	int		j;

	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE)
	{
		i = read(fd_in, buf, BUFFER_SIZE);
		if (i <= 0)
			break ;
		write(fd_out, buf, i);
		if (i < 0)
			break ;
		j = 0;
		while (j < BUFFER_SIZE)
			buf[j ++] = '\0';
	}
	close(fd_in);
	close(fd_out);
	if (i < 0)
		ft_error_int(23, 1, NULL, NULL);
	exit(0);
}

static int	ft_type_redir(char	*str)
{
	if (str[0] == '<' && str[1] != '<')
		return (1);
	else if (str[0] == '>' && str[1] != '>')
		return (2);
	else if (str[0] == '>' && str[2] != '>')
		return (3);
	return (0);
}

static int	ft_str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i ++;
	if (!str[i])
		return (1);
	return (0);
}

static int	ft_give_fd(int itype, char *str)
{
	if (ft_str_is_digit(str))
		return (ft_atoi(str));
	else if (itype == 1)
		return (open(str, O_RDONLY));
	else if (itype == 2)
		return (open(str, O_CREAT | O_TRUNC | O_WRONLY, 0644));
	else if (itype == 3)
		return (open(str, O_CREAT | O_APPEND | O_WRONLY, 0644));
	return (-1);
}

void	ft_make_redir(char **array)
{
	int		fd;

	if (ft_type_redir(array[0]) == 0)
		return ;
	if (!array[1])
		ft_error_int(201, 1, array, NULL);
	fd = ft_give_fd(ft_type_redir(array[0]), array[1]);
	if (ft_type_redir(array[0]) == 1)
		ft_redir(fd, 1);
	else if (ft_type_redir(array[0]) == 2 || ft_type_redir(array[0]) == 3)
		ft_redir(0, fd);
}
