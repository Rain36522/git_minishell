/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:01:00 by pudry             #+#    #+#             */
/*   Updated: 2023/12/08 09:20:11 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	ft_check_is_quote(char c, int i)
{
	if (c == '\"' && i == 2)
		i = 0;
	else if (c == '\"' && i == 0)
		i = 2;
	else if (c == '\'' && i == 0)
		i = 1;
	else if (c == '\'' && i == 1)
		i = 0;
	return (i);
}

int	ft_quotes(char *str, int istatus)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' && istatus == 2)
			istatus = 0;
		else if (str[i] == '\"' && istatus == 0)
			istatus = 2;
		else if (str[i] == '\'' && istatus == 1)
			istatus = 0;
		else if (str[i] == '\'' && istatus == 0)
			istatus = 1;
		if (str[i] == '|' && istatus == 0)
			return (0);
		i++;
	}
	return (istatus);
}

int	ft_str_end_quotes(char *str, int i)
{
	i = 0;
	while (*str)
	{
		i = ft_check_is_quote(*str, i);
		str ++;
	}
	return (i);
}

// void	ft_put_array(char **array)
// {
// 	int		i;

// 	i = 0;
// 	if (!array)
// 		exit(0);
// 	ft_putstr_fd("array : \n", 2);
// 	ft_putstr_fd("---------------------------------------------\n", 2);
// 	while (array[i])
// 	{
// 		ft_putstr_fd(array[i], 2);
// 		ft_putstr_fd("\n", 2);
// 		ft_putstr_fd("-----------------------------------------\n", 2);
// 		i ++;
// 	}
// }
t_lst	*ft_add_end_lst_lst(t_lst *lst, t_lst *ptr)
{
	t_lst	*mem_lst;

	if (!lst)
		return (ptr);
	mem_lst = lst;
	while (lst->next)
		lst = lst->next;
	lst->next = ptr;
	return (mem_lst);
}

t_lst	*ft_utils_open_quotes(t_lst *ptr, t_lst *lst, int fd)
{
	char	*scmd;

	while (ft_str_end_quotes(ptr->str, 0) != 0)
	{
		scmd = get_next_line(fd);
		if (!scmd)
		{
			ft_free_file_lst(lst, 0, NULL);
			ft_error_int(201, 0, NULL, ptr->str);
			free(ptr);
			return (NULL);
		}
		ptr->str = ft_strjoin_free(ptr->str, scmd);
		free(scmd);
		if (!ptr->str)
		{
			free(ptr);
			ft_free_file_lst(lst, 12, NULL);
			return (NULL);
		}
	}
	return (ptr);
}
