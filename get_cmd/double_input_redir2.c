/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_input_redir2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:44 by pudry             #+#    #+#             */
/*   Updated: 2023/11/23 16:49:12 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

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
	while(array[i])
	{
		if (ft_strncmp(array[i], "<<", 3) == 0)
		{
			// ft_replace_str_array(array, i, lst->filename, lst);
			ft_replace_str_array(array, i + 1, "", lst);
			i ++;
		}
		i ++;
	}
	return (array);
}
