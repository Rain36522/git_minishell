/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:09:46 by pudry             #+#    #+#             */
/*   Updated: 2023/11/14 18:28:16 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static char	ft_is_string(char  ptr, char quote)
{
	if (ptr == '\'' && quote == '0')
		quote = '\'';
	else if (ptr == '\"' && quote == '0')
		quote = '\"';
	else if (ptr == '\'' && quote == '\'')
		quote = '0';
	else if (ptr == '\"' && quote == '\"')
		quote = '0';
	return (quote);
}

// This fonction save the word inside the list 
// with the file name that will be given.
static t_incmd	*ft_add_end_lst(t_incmd *lst, char  *wrd)
{
	t_incmd	*lst_wrd;
	t_incmd	*lst_start;

	lst_start = lst;
	lst_wrd = (t_incmd *) malloc(sizeof(t_incmd) * 1);
	if (!lst_wrd)
		return (ft_free_lst(lst));
	lst_wrd->filename = (char *) malloc(sizeof(char) * 10);
	if (lst_wrd->filename)
		return (ft_free_lst(lst));
	lst_wrd->next = NULL;
	lst_wrd->wrd = wrd;
	if (!lst)
	{
		lst_wrd->filename = "tmp_a.tmp\0";
		lst = lst_wrd;
		return (lst);
	}
	while (lst->next)
		lst = lst->next;
	lst_wrd->filename = lst->filename;
	lst_wrd->filename[4] ++;
	lst->next = lst->wrd;
	return (lst_start);
}

// This fonction put in the list the word after the '<<'
t_incmd	*ft_lst_word(char *ptr, t_incmd *lst)
{
	int		isize;
	char	quote;
	char	*wrd;

	isize = 0;
	quote = '0';
	while (*ptr && (*ptr == ' ' || *ptr == '\t'))
		ptr ++;
	while (ptr[isize] && (ptr[isize] == ' ' || ptr[isize] == '\t') \
		&& quote == '0')
		quote = ft_is_string(ptr[isize ++], quote);
	wrd = (char *) malloc(sizeof(char) * (isize + 1));
	if (!wrd)
		return (ft_free_lst(lst));
	wrd[isize --] = '\0';
	while (isize >= 0)
	{
		wrd[isize] = ptr[isize];
		isize ++;
	}
	return (ft_add_end_lst(lst, wrd));
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
		ilstsize += ft_strlen(lst->wrd);
		isize += ft_strlen(lst->filename);
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
	return (isize);
}

char	*ft_str_rplace_word(char *scmd, t_incmd *lst)
{
	int		isize;
	int		ilstsize;
	char	*cmd;
	t_incmd *mem_lst;
	int		i;

	ilstsize = 0;
	isize = 0;
	mem_lst = lst;
	while (lst)
	{
		ilstsize += ft_strlen(lst->wrd);
		isize += ft_strlen(lst->filename);
		lst = lst->next;
	}
	while ()
	
}
