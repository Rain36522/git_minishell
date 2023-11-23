/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_input_redir2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:44 by pudry             #+#    #+#             */
/*   Updated: 2023/11/23 17:28:40 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

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

	i = 0;
	while (array[i])
	{
		if (ft_strncmp(array[i], "<<", 3) == 0)
		{
			ft_replace_str_array(array, i, "<", lst);
			ft_replace_str_array(array, i + 1, lst->read_fd ,lst);
			i ++;
			lst = lst->next;
		}
		i ++;
	}
	return (array);
}

static void	ft_write_dat_in_file(t_incmd *lst)
{
	char	*str;
	int		isize;

	str = readline("> ");
	isize = ft_strlen(lst->wrd) + 1;
	ft_printf("isize : %i\n", isize);
	while (ft_strncmp(str, lst->wrd, isize))
	{
		ft_putstr_fd(str, lst->fd[1]);
		ft_putstr_fd("\n", lst->fd[1]);
		str = readline("> ");		
	}
	close(lst->fd[1]);
}

void	ft_write_file(t_incmd *lst)
{
	while (lst)
	{
		ft_write_dat_in_file(lst);
		lst = lst->next;
	}
}
