/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_input_redir2.c.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:44 by pudry             #+#    #+#             */
/*   Updated: 2023/11/22 20:23:52 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

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

static char	**ft_swap_str(char **array)
{
	char	*ptr1;
	char	*ptr2;
	int		i;

	ptr1 = array[0];
	ptr2 = array[1];
	i = 2;
	while (array[i])
	{
		array[i - 2] = array[i];
		i ++;
	}
	array[i - 1] = ptr2;
	array[i - 2] = ptr1;
	return (array);
}

char	**ft_replace_str_array(char **a, int ipos, char *new_str, t_incmd *lst)
{
	free(a[ipos]);
	a[ipos] = ft_strdup(new_str);
	if (!a[ipos])
	{
		ft_error_int(12, 0, a, NULL);
		ft_free_lst(lst, NULL);
		ft_error_array(12, 1, a + ipos + 1, NULL);
	}
	return (a);
}

char	**ft_replace_redir(t_incmd *lst, char **array)
{
	int		i;
	t_incmd	*mem_lst;

	i = 1;
	mem_lst = lst;
	if (ft_strncmp(array[0], "<<", 3) == 0)
		array = ft_swap_str(array);
	while(array[i]);
	{
		if (ft_strncmp(array[i], "<<", 3) == 0)
		{
			ft_replace_str_array(array, i ++, lst->filename, lst);
			ft_replace_str_array(array, i, "", lst);
		}
		i ++;
	}
}
