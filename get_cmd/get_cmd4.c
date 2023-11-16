/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:44 by pudry             #+#    #+#             */
/*   Updated: 2023/11/16 09:17:48 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static char *ft_first_filen_name(void)
{
	char	*str;
	char	*pid;

	pid = ft_itoa(getpid());
	if (!pid)
		return (NULL);
	str = ft_strjoin(pid, "_a.tmp");
	free(pid);
	return (str);
}

char	*ft_name_file(char *str)
{
	char	*pid;
	int		i;

	if (!str)
		return (ft_first_filen_name());
	i = 0;
	str = ft_strdup(str);
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '_')
		i ++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	str[i + 1] ++;
	return (str);
}
static int	ft_create_file(char *filename, char *wrd)
{
	int		fd;
	char	*ptr;
	int		isize;
	char	*scmd;

	fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
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
		lst =lst->next;
	}
	ft_free_lst(mem_lst, NULL);
	return (i);
}
