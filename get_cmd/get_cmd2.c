/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:09:46 by pudry             #+#    #+#             */
/*   Updated: 2023/11/15 15:11:43 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	ft_is_string(char  ptr, char quote)
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

// This function detect end of str if there is a | < > outside of quote.
int	ft_check_end_string(char ptr, char quote)
{
	if (quote != '0')
		return (0);
	if (ptr == ' ' || ptr == '\t')
		return (1);
	else if (ptr == '<' || ptr == '>' || ptr == '|')
		return (2);
	return (0);
}

static char	*ft_name_file(char *str)
{
	char	*pid;
	int		i;

	pid  = ft_itoa(getpid());
	if (!str)
	{
		pid  = ft_itoa(getpid());
		str = ft_strjoin(pid, "_a.tmp");
		free(pid);
		return (NULL);
	}
	i = 0;
	str = ft_strdup(str);
	if (!str)
		return (NULL);
	while (str && str[i] && str[i] != '_')
		i ++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	str[i + 1] ++;
	return (str);
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
		return (ft_free_lst(lst, wrd));
	lst_wrd->filename = (char *) malloc(sizeof(char) * 10);
	if (!lst_wrd->filename)
		return (ft_free_lst(lst, wrd));
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
	//lst_wrd->filename[4] += 1;
	lst->next = lst_wrd;
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
	while (ptr[isize] && ft_check_end_string(ptr[isize], quote) == 0)
		quote = ft_is_string(ptr[isize ++], quote);
	wrd = (char *) malloc(sizeof(char) * (isize + 1));
	if (!wrd)
		return (ft_free_lst(lst, NULL));
	wrd[isize --] = '\0';
	while (isize >= 0)
	{
		wrd[isize] = ptr[isize];
		isize --;
	}
	return (ft_add_end_lst(lst, wrd));
}
