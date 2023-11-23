/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_input_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:41:45 by pudry             #+#    #+#             */
/*   Updated: 2023/11/23 16:55:50 by pudry            ###   ########.fr       */
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

static t_incmd	*ft_create_lst(t_incmd *lst, char *wrd)
{
	t_incmd	*ptr;

	ptr = (t_incmd *) 
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
			lst = ft_create_lst(lst, array[i + 1]);
	}
}

