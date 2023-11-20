/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:44 by pudry             #+#    #+#             */
/*   Updated: 2023/11/16 18:17:04 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

//This funtion generate a new file name or 
//make a copy of the given file name and incrase
char	*ft_name_file(char *str)
{
	char	*pid;
	int		i;

	if (!str)
		return (ft_strdup("tmp_a.tmp"));
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

	ft_putstr_fd("57_3\n", 1);
	fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	ft_printf("58_3\n");
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
	ft_printf(("write file\n"));
	while (lst)
	{
		ft_printf("filename : %s\n", lst->filename);
		lst = lst->next;
	}
	while (i >= 0 && lst)
	{
		ft_printf("86_3\n");
		i = ft_create_file(lst->filename, lst->wrd);
		ft_printf("87\n");
		lst =lst->next;
	}
	ft_printf("89\n");
	ft_free_lst(mem_lst, NULL);
	return (i);
}
