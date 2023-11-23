/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:39 by pudry             #+#    #+#             */
/*   Updated: 2023/11/23 12:39:00 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static void	ft_free_file_lst(t_lst *lst, int ierror)
{
	t_lst	*ptr;

	while (lst)
	{
		ptr = lst->next;
		free(lst->str);
		free(lst);
		lst = ptr;
	}
	if (ierror)
		ft_error_int(ierror, 1, NULL, NULL);
}

t_lst	*ft_read_file(int fd)
{
	t_lst	*lst;
	t_lst	*ptr;
	char	*str;
	t_lst	*mem_lst;

	mem_lst = NULL;
	str = get_next_line(fd);
	while (str)
	{
		ptr = (t_lst *) malloc(sizeof(t_lst) * 1);
		if (!lst)
			ft_free_file_lst(lst, 12);
		ptr->str = str;
		ptr->next = NULL;
		lst = mem_lst;
		while (mem_lst)
			mem_lst = mem_lst->next;
		mem_lst = ptr;
		if (lst)
			mem_lst = lst;
		str = get_next_line(fd);
	}
	return (lst);
}

static char	**ft_put_in_array(char **array, t_lst *lst)
{
	int		i;
	t_lst	*mem_lst;
	t_lst	*ptr;

	i = 0;
	mem_lst = lst;
	while (i < 0)
	{
		array[i] = lst->str;
		lst = lst->next;
		i ++;
	}
	while (mem_lst)
	{
		ptr = mem_lst->next;
		free(mem_lst);
		mem_lst = ptr;
	}
	return (array);
}

static char	**ft_put_lst_array(t_lst *mem_lst)
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
	array = (char **) malloc(sizeof(char *) * (isize + 1));
	if (!array)
		ft_free_file_lst(lst, 12);
	array[isize] = NULL;
	array = ft_put_in_array(array, lst);
	return (array);
}

char	**ft_file_to_array(int fd)
{
	t_lst	*lst;
	char	**array;

	lst = ft_read_file(fd);
	array = ft_put_lst_array(lst);
	return (array);
}