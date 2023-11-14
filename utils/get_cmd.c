/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:05:47 by pudry             #+#    #+#             */
/*   Updated: 2023/11/14 16:52:25 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*
** This function return a pointer at the end of the redirection
** If there is no redirection or the redirection is inside a string;
** The function return NULL.
*/
char	*ft_dbl_redi_in(char *str)
{
	while (*str)
	{
		while (*str && *str != "\"" && *str != '\'' && *str != '<')
			str ++;
		if (*str == '\'')
			while (*str && *str != '\'')
				str ++;
		else if (*str == '\"')
			while (*str && *str != '\"')
				str ++;
		else if (*str && *str == '<' && str[1] == '<')
			return (str + 2);
	}
	return (NULL);
}

/*
 *	Check if single or double quotes aren't close
 *	return != 0 if quotes aren't closed
 *	2 = double
 *	1 = simple
 */
static int	ft_quotes(char *str, int istatus)
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
static t_incmd	*ft_redir_in_dbl(char *scmd)
{
	char	*ptr;
	char	*lst;

	ptr = ft_dbl_redi_in(scmd);
	while (ptr)
		if (ft_quotes(ptr, 0) != 0)
			return (scmd);
		lst = ft_lst_word(ptr, lst);
		if (!lst)
			return (NULL);
		ptr = ft_dbl_redi_in(ptr);
	scmd = ft_cmd_replace_dbl_in(scmd, lst);

}

/*
	while (i != 0 && scmd && check_up_down_key(scmd) == 0)
	{
		scmd = ft_strjoin(scmd, "\n");
		ft_printf("%s", scmd);
		ptr = scmd;
		ptr2 = readline("> ");
		i = ft_quotes(ptr2, i);
		scmd = ft_strjoin(ptr, ptr2);
		free(ptr);
		free(ptr2);
	}
*/
char	*get_cmd(char *prompt)
{
	char	*scmd;
	int		i;

	scmd = readline(prompt);
	if (ft_dbl_redi_in(scmd))
		ft_redir_in_dbl(scmd);
	i = ft_quotes(scmd, 0);

	if (!scmd)
		return (NULL);
	return (scmd);
}
