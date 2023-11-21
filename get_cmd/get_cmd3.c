/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:44 by pudry             #+#    #+#             */
/*   Updated: 2023/11/21 15:34:47 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

//This funtion generate a new file name or 
//make a copy of the given file name and incrase
char	*ft_name_file(char *str)
{
	int		i;

	if (!str)
		return (ft_strdup("tmp_a.tmp"));
	i = 0;
	str = ft_strdup(str);
	if (!str)
		return (ft_error_str(12, 1, NULL, NULL));
	while (str[i] && str[i] != '_')
		i ++;
	if (!str[i])
		return (ft_error_str(202, 0, NULL, str));
	str[i + 1] += 1;
	return (str);
}

static int	ft_create_file(char *filename, char *wrd)
{
	int		fd;
	int		isize;
	char	*scmd;

	fd = open(filename, \
		O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		return (fd);
	isize = ft_strlen(wrd) + 1;
	scmd = readline("$ > ");
	while (ft_strncmp(scmd, wrd, isize) != 0)
	{
		ft_putstr_fd(scmd, fd);
		ft_putstr_fd("\n", fd);
		free(scmd);
		scmd = readline("$ > ");
	}
	free(scmd);
	close(fd);
	return (1);
}

int	ft_write_file(t_incmd *lst)
{
	int		i;
	t_incmd	*mem_lst;

	i = 0;
	mem_lst = lst;
	while (i >= 0 && lst)
	{
		i = ft_create_file(lst->filename, lst->wrd);
		lst = lst->next;
	}
	ft_free_lst(mem_lst, NULL);
	return (i);
}
