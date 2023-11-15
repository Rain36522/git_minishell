/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:31:26 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/15 10:39:50 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "Includes/minishell.h"

// skip until the next ' or "
int	skip_until(const char *s, int i, char c)
{
	i++;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] && s[i] == c)
		i++;
	return (i);
}

// return 1 if char != | sp tab ' " < > found
// else: return 0
int	check_spe_case(char c)
{
	if (c == '\'')
		return (1);
	else if (c == '\"')
		return (1);
	else if (c == '|')
		return (1);
	else if (c == '<' || c == '>')
		return (1);
	else if (c == 32)
		return (1);
	else if (c == 9)
		return (1);
	return (0);
}

// inc until s[i] != c
int	skip_pipe_or_dir(const char *s, int i, char c)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

// count the nbr of classical words and spe case
int	str_nbr(char const *s, int i, int j)
{
	while (s[i])
	{
		while (s[i] && (s[i] == 32 || s[i] == 9))
			i++;
		if ((s[i] == '>' || s[i] == '<') || s[i] == '|')
			j++;
		if ((s[i] == '>' || s[i] == '<') || s[i] == '|')
			i = skip_pipe_or_dir(s, i, s[i]);
		if (s[i] == '\'')
			j++;
		if (s[i] == '\'')
			i = skip_until(s, i, s[i]);
		if (s[i] == '\"')
			j++;
		if (s[i] == '\"')
			i = skip_until(s, i, '\"');
		if (s[i] && check_spe_case(s[i]) == 0)
			j++;
		while (s[i] && s[i] != 32 && s[i] != 9
			&& s[i] != '>' && s[i] != '<' && s[i] != '|')
			i++;
	}
	return (j);
}

// free all the tab in arg and return NULL
char	**free_split(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

int	main(void)
{
	char  		*s;
	char		**tab = NULL;
	
	s = "	 	 	ls 		-l ||||echo ecrit\"tout\"attache\'merciii\' 	 	 	|cat -e";
	tab = ft_split_minishell(s);
	int		i = 0;
	while (tab[i])
	{
	    printf("tab: %s\n", tab[i]);
	    i++;
	}
	printf("fin: %s\n", tab[i]);
	return (0);
}