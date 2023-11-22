/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_input_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:41:45 by pudry             #+#    #+#             */
/*   Updated: 2023/11/22 19:59:49 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

//This funtion generate a new file name or 
//make a copy of the given file name and incrase
static char	*ft_name_file(char *str)
{
	int		i;

	if (!str)
		return (ft_strdup("tmp_a.tmp"));
	i = 0;
	str = ft_strdup(str);
	if (!str)
		return (ft_error_str(12, 1, NULL, NULL));
	while (str[i] && str[i] != '_')
		i ++;
	if (!str[i])
		return (ft_error_str(202, 0, NULL, str));
	str[i + 1] += 1;
	return (str);
}

t_incmd	*ft_free_lst(t_incmd *lst, char *str)
{
	t_incmd	*nxt_lst;

	while (lst)
	{
		if (lst->filename)
			free(lst->filename);
		if (lst->wrd)
			free(lst->wrd);
		nxt_lst = lst->next;
		free(lst);
		lst = nxt_lst;
	}
	if (str)
		free(str);
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

t_incmd	*ft_make_lst(char **array)
{
	int		i;
	t_incmd	*lst;

	i = 0;
	while (array[i])
	{
		if (ft_strncmp(array[i], "<<", 3) == 0)
		{
			lst = ft_add_end_lst(lst, array[i + 1]);
			if (!lst)
			{
				ft_error_int(12, 1, array, NULL);
				return (NULL);
			}
		}
		i ++;
	}
	return (lst);
}
