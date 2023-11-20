/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:48:32 by pudry             #+#    #+#             */
/*   Updated: 2023/11/20 17:01:40 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

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

static int	ft_check_dbl_redi(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strncmp("<<", array[i], 3) == 0)
			return (1);
		i ++;
	}
	return (0);
}

static int	ft_check_dbl_redi_str(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (i == 0 && *str == '\"')
			i = 2;
		else if (i == 2 && *str == '\"')
			i = 0;
		else if (i == 0 && *str == '\'')
			i = 1;
		else if (i == 1 && *str == '\'')
			i = 0;
		else if (i == 0 && str[0] == '<' && str[1] == '<' && str[2] != '<')
			return (1);
		*str ++;
	}
	return (0);
}

void	ft_put_array(char **a)
{
	int	i;

	ft_printf("put array :\n");
	i = 0;
	while (a[i])
	{
		ft_printf("array : %s\n", a[i]);
		i ++;
	}
	ft_printf("finish\n");
}

char	**ft_make_cmd_quote(char *scmd)
{
	int		i;
	char	*ptr;
	char	*ptr2;
	char	acmd;

	if (ft_quotes(scmd, 0) == 0)
		return (ft_split_minishell(scmd));
	else if (ft_check_dbl_redi_str(scmd))
		ft_error_str(1000);
	i = ft_quotes(scmd, 0);
	while (i != 0 && scmd)
	{
		scmd = ft_strjoin(scmd, "\n");
		ptr = scmd;
		ptr2 = readline("> ");
		i = ft_quotes(ptr2, i);
		scmd = ft_strjoin(ptr, ptr2);
		free(ptr);
		free(ptr2);
	}
	if (!scmd)
		return (NULL);
	return (ft_split_minishell(scmd));
}

char	**get_cmd(char *prompt)
{
	char	*scmd;
	int		i;
	char	**array;

	scmd = readline(prompt);
	if (!scmd)
		return (NULL);
	add_history(scmd);
	if (ft_check_dbl_redi_str(scmd) == 1 && ft_quotes(scmd, 0) == 0)
	{
		array = ft_split_minishell(scmd);
		if (!array)
			return (NULL);
		free(scmd);
		scmd = NULL;
		return (ft_make_dbl_redir(array));
	}
	else
		return (ft_make_cmd_quote(scmd));
	if (scmd)
		free(scmd);
	return (NULL);
}

	// else
	// {
	// 	while (i != 0 && scmd)
	// 	{
	// 		scmd = ft_strjoin(scmd, "\n");
	// 		ft_printf("%s", scmd);
	// 		ptr = scmd;
	// 		ptr2 = readline("> ");
	// 		i = ft_quotes(ptr2, i);
	// 		scmd = ft_strjoin(ptr, ptr2);
	// 		free(ptr);
	// 		free(ptr2);
	// 	}
	// }
	// if (!scmd)
	// 	return (NULL);
	// return (scmd);
