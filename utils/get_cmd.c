/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:05:47 by pudry             #+#    #+#             */
/*   Updated: 2023/11/13 19:21:52 by pudry            ###   ########.fr       */
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
		i++;
	}
	return (istatus);
}



char	*get_cmd(char *prompt)
{
	char	*ptr;
	char	*ptr2;
	char	*scmd;
	int		i;

	scmd = readline(prompt);
	i = ft_quotes(scmd, 0);
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
	if (!scmd)
		return (NULL);
	return (scmd);
}
