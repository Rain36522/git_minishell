/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:36:06 by pudry             #+#    #+#             */
/*   Updated: 2023/11/15 12:51:07 by pudry            ###   ########.fr       */
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

static char	*ft_skip_word(char *scmd)
{
	char	ptr;

	ptr = '0';
	while (*scmd && (*scmd == ' ' || *scmd == '\t'))
		scmd ++;
	ptr = ft_is_string(*scmd, ptr);
	while (*scmd && ft_check_end_string(*scmd, ptr) == 0)
	{
		scmd ++;
		ptr = ft_is_string(*scmd, ptr);
	}
	return (scmd);
}

static int 	ft_cnt_new_cmd_size(char *scmd, t_incmd *lst)
{
	int		isize;
	int		ilstsize;
	char	*ptr;

	ilstsize = 0;
	isize = 0;
	while (lst)
	{
		isize += ft_strlen(lst->filename) + 1;
		lst = lst->next;
	}
	ptr = ft_dbl_redi_in(scmd);
	while (ptr)
	{
		isize += ptr - scmd;
		scmd = ft_skip_word(ptr);
		ptr = ft_dbl_redi_in(scmd);
		if (!ptr)
			isize += ft_strlen(scmd);
	}
	return (isize - ilstsize);
}

static char	*ft_add_filename(char *ptr, char *filename)
{
	int	i;

	i = 3;
	ptr[0] = ' ';
	ptr[1] = '<';
	ptr[2] = ' ';
	while (filename[i - 3])
	{
		ptr[i] = filename[i - 3];
		i ++;
	}
	ft_printf("filename : %s\n", ptr);
	ptr += i;
	return (ptr);
}

char	*ft_str_rplace_word(char *scmd, t_incmd *lst)
{
	int		isize;
	char	*ptr;
	char	*mem_ptr;

	isize = ft_cnt_new_cmd_size(scmd, lst);
	ptr = (char *) malloc(sizeof(char) * (isize + 1));
	if (!ptr)
		return (NULL);	
	ptr[isize] = '\0';
	mem_ptr = ptr;
	while (*scmd)
	{
		ft_printf("108 : %s\n", scmd);
		if (*scmd == '<' && scmd[1] == '<')
		{
			scmd += 2;
			ptr = ft_add_filename(ptr, lst->filename);
			ft_printf("ptr : %s\n", ptr);
			lst = lst->next;
			scmd = ft_skip_word(scmd);
		}
		*ptr = *scmd;
		ptr ++;
		scmd ++;
	}
	return (mem_ptr);
}
