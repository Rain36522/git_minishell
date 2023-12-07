/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_input_redir2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:44 by pudry             #+#    #+#             */
/*   Updated: 2023/12/07 10:45:53 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static char	**ft_replace_str_array(char **a, int ipos, \
												char *new_str, t_incmd *lst)
{
	a[ipos] = ft_free_str(a[ipos]);
	a[ipos] = ft_strdup(new_str);
	if (!a[ipos])
	{
		ft_error_int(12, 0, a, NULL);
		ft_free_lst(lst, NULL);
		ft_error_ptr(12, 1, a + ipos + 1, NULL);
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
			ft_replace_str_array(array, i++, "<", lst);
			ft_replace_str_array(array, i, lst->read_fd, lst);
			lst = lst->next;
		}
		i ++;
	}
	return (array);
}

static char	*ft_readline_redir(int i, t_incmd *lst, char **array, t_data *data)
{
	char	*str;

	str = readline(">> ");
	if (!str)
	{
		ft_free_lst(lst, NULL);
		data->env = ft_free_array(data->env);
		ft_error_int(125, 1, array, NULL);
	}
	if (*str)
		str = replace_dollar(str, i, data);
	return (str);
}

static void	ft_write_dat_in_file(t_incmd *lst, char **array, t_data *data)
{
	char	*str;
	int		isize;

	str = ft_readline_redir(0, lst, array, data);
	isize = ft_strlen(lst->wrd) + 1;
	while (ft_strncmp(str, lst->wrd, isize))
	{
		ft_putstr_fd(str, lst->fd[1]);
		str = ft_free_str(str);
		ft_putstr_fd("\n", lst->fd[1]);
		str = ft_readline_redir(0, lst, array, data);
	}
	str = ft_free_str(str);
	close(lst->fd[1]);
}

void	ft_write_file(t_incmd *lst, char **array, t_data *data)
{
	t_incmd	*lst_next;

	while (lst)
	{
		lst_next = lst->next;
		ft_write_dat_in_file(lst, array, data);
		lst->read_fd = ft_free_str(lst->read_fd);
		lst->wrd = ft_free_str(lst->wrd);
		lst = lst->next;
		free(lst);
	}
}
