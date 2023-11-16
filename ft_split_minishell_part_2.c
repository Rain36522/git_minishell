/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_minishell_part_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:39:14 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/15 14:14:53 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"
#include <stdlib.h>
#include <stdio.h>

// duplicate for pipe or dir in tab
int	dup_pip_dir(char **tab, const char *s, int i, char c)
{
	int		len;
	int		j;
	char	*str;

	len = (skip_pipe_or_dir(s, i, c) - i) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (-1);
	j = 0;
	while (s[i] && s[i] == c)
		str[j++] = s[i++];
	str[j] = '\0';
	*tab = str;
	return (i);
}

// return 1 if tab sp pipe or dir
// else return 0
int	spe_case_out_quotes(char c)
{
	if (c == '|')
		return (1);
	else if (c == 32)
		return (1);
	else if (c == 9)
		return (1);
	else if (c == '<')
		return (1);
	else if (c == '>')
		return (1);
	return (0);
}

// return the len of the str to dup
int	len_dup_str(const char *s, int i)
{
	int		ilen;
	char	tmp;

	ilen = i;
	while (s[ilen] && spe_case_out_quotes(s[ilen]) == 0)
	{
		while (s[ilen] && spe_case_out_quotes(s[ilen]) == 0
			&& s[ilen] != '\'' && s[ilen] != '\"')
			ilen++;
		if (s[ilen] && (s[ilen] == '\'' || s[ilen] == '\"'))
		{
			tmp = s[ilen];
			ilen++;
			while (s[ilen] && s[ilen] != tmp)
				ilen++;
			if (s[ilen] && s[ilen] == tmp)
				ilen++;
		}
	}
	return (ilen);
}

// dup str until pipe dir or tab sp \0
int	dup_str(char **tab, const char *s, int i)
{
	int		ilen;
	int		j;
	char	*str;

	ilen = len_dup_str(s, i);
	str = malloc(sizeof(char) * (ilen - i) + 1);
	if (!str)
		return (-1);
	j = 0;
	while (i < ilen && s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	*tab = str;
	return (i);
}

char	**ft_split_minishell(char const *s)
{
	char	**tab;
	char	**first;
	int		i;

	i = 0;
	tab = ft_calloc(sizeof(char *), (str_nbr(s, 0, 0) + 1));
	if (!tab)
		return (NULL);
	first = tab;
	while (s[i])
	{
		while (s[i] && s[i] == 32 || s[i] == 9)
			i++;
		if (s[i] == '>' || s[i] == '<' || s[i] == '|')
			i = dup_pip_dir(tab, s, i, s[i]);
		else if (s[i] == '\'' || s[i] == '\"' )
			i = dup_str(tab, s, i);
		else if (s[i] && check_spe_case(s[i]) == 0)
			i = dup_str(tab, s, i);
		tab++;
		if (i == -1)
			return (free_split(first));
	}
	return (first);
}
