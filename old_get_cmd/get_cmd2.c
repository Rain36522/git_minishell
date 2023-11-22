/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:48:32 by pudry             #+#    #+#             */
/*   Updated: 2023/11/22 20:19:00 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_incmd	*ft_free_lst(t_incmd *lst, char *scmd)
{
	t_incmd	*nxt_lst;

	while (lst)
	{
		free(lst->filename);
		free(lst->wrd);
		nxt_lst = lst->next;
		free(lst);
		lst = nxt_lst;
	}
	if (scmd)
		free(scmd);
	return (NULL);
}

static t_incmd	*ft_add_end_lst(t_incmd *lst, char *wrd)
{
	t_incmd	*lst_wrd;
	t_incmd	*lst_start;

	lst_start = lst;
	lst_wrd = (t_incmd *) malloc(sizeof(t_incmd) * 1);
	if (!lst_wrd)
		return (ft_free_lst(lst, wrd));
	lst_wrd->next = NULL;
	lst_wrd->wrd = wrd;
	if (!lst)
	{
		lst_wrd->filename = ft_name_file(NULL);
		return (lst_wrd);
	}
	while (lst->next)
		lst = lst->next;
	lst_wrd->filename = ft_name_file(lst->filename);
	lst->next = lst_wrd;
	if (!lst_wrd->filename)
		return (ft_free_lst(lst_start, NULL));
	return (lst_start);
}

char	**ft_make_dbl_redir(char **array)
{
	int		i;
	t_incmd	*lst;
	t_incmd	*mem_lst;

	lst = NULL;
	i = 0;
	while (array[i + 1])
	{
		if (ft_strncmp("<<", array[i], 3) == 0)
		{
			lst = ft_add_end_lst(lst, array[i + 1]);
			mem_lst = lst;
			while (lst->next)
				lst = lst->next;
			array = ft_replace_str_array(array, i, "<");
			if (array)
				array = ft_replace_str_array(array, i + 1, lst->wrd);
			if (!array)
				return (NULL);
			lst = mem_lst;
		}
		i ++;
	}
	if (!lst)
		return (ft_error_array(12, 1, array, NULL));
	if (ft_write_file(mem_lst) < 0)
		return (NULL);
	return (array);
}