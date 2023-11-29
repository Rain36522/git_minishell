/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:39 by pudry             #+#    #+#             */
/*   Updated: 2023/11/29 16:35:06 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_free_file_lst(t_lst *lst, int ierror, char **array)
{
	t_lst	*ptr;

	while (lst)
	{
		ptr = lst->next;
		free(lst->str);
		free(lst);
		lst = ptr;
	}
	if (ierror != 0)
		ft_error_int(ierror, 1, NULL, NULL);
}

t_lst	*ft_read_file(int fd)
{
	t_lst	*lst;
	t_lst	*ptr;
	char	*str;

	lst = NULL;
	str = get_next_line(fd);
	while (str)
	{
		ptr = (t_lst *) malloc(sizeof(t_lst) * 1);
		if (!ptr)
			ft_free_file_lst(lst, 12, NULL);
		ptr->str = str;
		ptr->next = NULL;
		ptr = ft_utils_open_quotes(ptr, lst, fd);
		lst = ft_add_end_lst_lst(lst, ptr);
		str = get_next_line(fd);
	}
	close(fd);
	return (lst);
}

static char	**ft_put_in_array(char **array, t_lst *lst, int isize)
{
	int		i;
	t_lst	*mem_lst;
	t_lst	*ptr;
	char	*str;

	if (isize == 1)
		i = 0;
	else
		i = 1;
	mem_lst = lst;
	while (lst)
	{
		array[i] = lst->str;
		lst = lst->next;
		i ++;
	}
	while (mem_lst)
	{
		lst = mem_lst->next;
		free(mem_lst);
		mem_lst = lst;
	}
	return (array);
}

static char	**ft_put_lst_array(t_lst *mem_lst, int *fd)
{
	int		isize;
	t_lst	*lst;
	char	**array;

	lst = mem_lst;
	isize = 0;
	while (mem_lst->next)
	{
		isize ++;
		mem_lst = mem_lst->next;
	}
	ft_printf("lst size : %i,", isize);
	if (isize > 1)
		isize += 2;
	ft_printf("isize : %i\n", isize);
	array = (char **) malloc(sizeof(char *) * (isize + 1));
	if (!array)
		ft_free_file_lst(lst, 12, NULL);
	array[isize] = NULL;
	if (isize > 1)
	{
		array[0] = ft_itoa(fd[0]);
		array[isize - 1] = ft_itoa(fd[1]);
	}
	array = ft_put_in_array(array, lst, isize);
	return (array);
}

t_acmd	*ft_file_to_array(int fd)
{
	t_lst	*lst;
	int		i;
	int		*fd_pipex;
	t_acmd	*acmd_data;

	acmd_data = (t_acmd *) malloc(sizeof(t_acmd) * 1);
	if (!acmd_data)
		ft_error_int(12, 1, NULL, NULL);
	lst = ft_read_file(fd);
	acmd_data = ft_util_add_pipe(acmd_data);
	acmd_data->array = ft_put_lst_array(lst, acmd_data->fd_pipe);
	if (acmd_data->array[1])
		i = 1;
	while (acmd_data->array[i + 1] )
	{
		acmd_data->array[i] = ft_strdup_remov(acmd_data->array[i]);
		i++;
	}
	acmd_data->isize = 0;
	while (acmd_data->array[acmd_data->isize])
		acmd_data->isize ++;
	return (acmd_data);
}
