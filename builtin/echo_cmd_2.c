/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:34:45 by csil              #+#    #+#             */
/*   Updated: 2023/11/25 20:37:35 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"
#include "Includes/header_builtin.h"

int	dollar_gestion(char *str, int i, char **envp)
{
	int		j;
	int		k;
	int		start;

	start = i;
	k = 0;
	j = 0;
	while (str[i] && str[i] != 32 && str[i] != '\'' && str[i] != '\"')
		i++;
	while (envp[j])
	{
		if (ft_strncmp(envp[j], str + start + 1, i - start - 1) == 0)
		{
			while (envp[j][k] && envp[j][k] != '=')
				k++;
			printf ("%s", envp[j] + k + 1);
			return (i);
		}
		j++;
		k = 0;
	}
	return (i);
}

int	print_until(char *str, int i, char c, char **envp)
{
	while (str[i] && str[i] != c)
	{
		if (str[i] == '$')
			i = dollar_gestion(str, i, envp);
		printf ("%c", str[i]);
		i++;
	}
	if (str[i] && str[i] == c)
		i++;
	return (i);
}
