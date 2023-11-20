/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:48:32 by pudry             #+#    #+#             */
/*   Updated: 2023/11/16 14:46:03 by pudry            ###   ########.fr       */
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

static t_incmd	*ft_add_end_lst(t_incmd *lst, char  *wrd)
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
	return (lst_start);
}

static char	**ft_replace_str_array(char **array, int ipos, char *new_str)
{
	int	i;
	free(array[ipos]);
	array[ipos] = ft_strdup(new_str);
	if (!array[ipos])
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i ++;
			if(i == ipos)
				i ++;
		}
		free(array);
		return (NULL);
	}
	return (array);
}

char	**ft_make_dbl_redir(char **array)
{
	int		i;
	t_incmd	*lst;
	t_incmd	*mem_lst;

	lst = NULL;
	i = 0;
	ft_printf("84_2\n");
	while (array[i + 1])
	{
		if (ft_strncmp("<<", array[i], 3) == 0)
		{
			lst = ft_add_end_lst(lst, array[i + 1]);
			mem_lst = lst;
			while (lst->next)
				lst = lst->next;
			array = ft_replace_str_array(array, i , "<");
			if (array)
				array = ft_replace_str_array(array, i + 1 , lst->filename);
			if (!array)
				return (NULL);
			lst = mem_lst;
		}
		i ++;
	}
	while (lst)
	{
		ft_printf("filename : %s\n", lst->filename);
		lst = lst->next;
	}
	if (!lst)
		ft_printf("no_lst\n");
	lst = mem_lst;
	if (ft_write_file(mem_lst) < 0)
		return (NULL);
	return (array);
}
