/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_input_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:41:45 by pudry             #+#    #+#             */
/*   Updated: 2023/11/23 17:07:33 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

//This funtion generate a new file name or 
//make a copy of the given file name and incrase

t_incmd	*ft_free_lst(t_incmd *lst, char *str)
{
	t_incmd	*nxt_lst;

	while (lst)
	{
		if (lst->wrd)
			free(lst->wrd);
		if (lst->read_fd)
			free(lst->read_fd);
		nxt_lst = lst->next;
		free(lst);
		lst = nxt_lst;
	}
	if (str)
		free(str);
	return (NULL);
}

static t_incmd	*ft_add_end_lstincmd(t_incmd *lst, t_incmd *ptr)
{
	t_incmd	*mem_lst;

	if (!lst)
		return (ptr);
	mem_lst = lst;
	while (lst->next)
		lst = lst->next;
	ptr = lst->next;
	return (mem_lst);
}

static t_incmd	*ft_create_lst(t_incmd *lst, char *wrd, char **array)
{
	t_incmd	*ptr;

	ptr = (t_incmd *) malloc(sizeof(t_incmd));
	if (!ptr)
		return (ft_free_lst(lst, NULL));
	ptr->next = NULL;
	ptr->wrd = ft_strdup(wrd);
	if (!ptr->wrd)
		return (ft_free_lst(lst, wrd));
	if (pipe(ptr->fd) < 0)
	{
		ft_free_lst(lst, NULL);
		ft_error_int(32, 1, array, wrd);
		return (NULL);
	}
	ptr->read_fd = ft_itoa(ptr->fd[0]);
	if (!ptr->read_fd)
	{
		ft_free_lst(lst, NULL);
		ft_error_int(32, 1, array, wrd);
		return (NULL);
	}
	return(ft_add_end_lstincmd(lst, ptr));
}

t_incmd	*ft_make_lst(char **array)
{
	int		i;
	t_incmd	*lst;

	i = 0;
	lst = NULL;
	while (array[i])
	{
		if (ft_strncmp(array[i], "<<", 3) == 0)
			lst = ft_create_lst(lst, array[i + 1], array);
		i ++;
	}
	return (lst);	
}

