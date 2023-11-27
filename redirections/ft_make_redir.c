/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:10:35 by pudry             #+#    #+#             */
/*   Updated: 2023/11/26 10:21:58 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "Includes/minishell.h"

static int	ft_type_redir(char	*str)
{
	if (str[0] == '<' && str[1] != '<')
		return (1);
	else if (str[0] == '>' && str[1] != '>')
		return (2);
	else if (str[0] == '>' && str[1] && str[2] != '\0')
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

static int	ft_give_fd(int	itype, char *str)
{
	if (ft_str_is_digit(str))
		return (ft_atoi(str));
	else if (itype == 1)
		return (open(str, O_RDONLY));
	else if (itype == 2)
		return (open(str, O_CREAT | O_TRUNC | O_WRONLY));
	else if (itype == 3)
		return (open(str, O_CREAT | O_APPEND | O_WRONLY));
	return (-1);	
}

void	ft_make_redir(char	*str)
{
	char	**array;
	int		fd;

	array = ft_split_minishell(str);
	if (!array)
		ft_error_int(12, 1, NULL, str);
	if (!array[1])
		ft_error_int(201, 1, array, str);
	fd = ft_give_fd(ft_type_redir(array[0]), array[1]);
	if (ft_type_redir(array[0]) == 1)
		ft_redir_in(fd);
	else if (ft_type_redir(array[0]) == 2 || array[0] == 3) 
		ft_redir_out(fd);
}