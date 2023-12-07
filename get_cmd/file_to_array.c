/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:39 by pudry             #+#    #+#             */
/*   Updated: 2023/12/07 10:46:26 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_free_file_lst(t_lst *lst, int ierror, char **array)
{
	t_lst	*ptr;

	while (lst)
	{
		ptr = lst->next;
		lst->str = ft_free_str(lst->str);
		free(lst);
		lst = ptr;
	}
	lst = NULL;
	array = ft_free_array(array);
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
		if (!ptr)
			break ;
		lst = ft_add_end_lst_lst(lst, ptr);
		str = get_next_line(fd);
	}
	close(fd);
	if (!ptr)
		return (NULL);
	return (lst);
}

static char	**ft_put_in_array(char **array, t_lst *lst, int isize)
{
	int		i;
	t_lst	*mem_lst;

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
	while (mem_lst)
	{
		isize ++;
		mem_lst = mem_lst->next;
	}
	if (isize > 1)
		isize += 2;
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

t_acmd	*ft_file_to_array(int fd, int fd_out, t_data *data)
{
	t_lst	*lst;
	int		i;
	int		j;
	t_acmd	*acmd_data;

	close(fd_out);
	lst = ft_read_file(fd);
	if (!lst)
		return (NULL);
	acmd_data = (t_acmd *) malloc(sizeof(t_acmd) * 1);
	if (!acmd_data)
		ft_free_file_lst(lst, 12, NULL);
	acmd_data = ft_util_add_pipe(acmd_data);
	acmd_data->array = ft_put_lst_array(lst, acmd_data->fd_pipe);
	j = 0;
	if (acmd_data->array[1])
		j = 1;
	i = j - 1;
	while (acmd_data->array[++i + j])
		acmd_data->array[i] = ft_strdup_remov(acmd_data->array[i], acmd_data);
	acmd_data->isize = ft_array_len(acmd_data->array);
	acmd_data = treat_input(acmd_data, data);
	return (acmd_data);
}
