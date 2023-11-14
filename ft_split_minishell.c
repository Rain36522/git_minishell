/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:31:26 by cduffaut          #+#    #+#             */
/*   Updated: 2023/10/24 14:35:40 by cduffaut         ###   ########.fr       */
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
		if ((s[i] == '>' || s[i] == '<')|| s[i] == '|')
			j++;
		if ((s[i] == '>' || s[i] == '<')|| s[i] == '|')
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
		while (s[i] && check_spe_case(s[i]) == 0)
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
// duplicate for double or single quotes
int	dup_quote(char **tab, const char *s, int i, char c)
{
	int		len;
	int		j;
	char	*str;

	len = (skip_until(s, i, c) - i) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (-1);
	j = 0;
	if (s[i] && s[i] == c)
		str[j++] = s[i++];
	while (s[i] && s[i] != c)
		str[j++] = s[i++];
	if (s[i] && s[i] == c)
		str[j++] = s[i++];
	str[j] = '\0';
	*tab = str;
	return (i);
}
int	dup_str(char **tab, const char *s, int i)
{
	int	tmp;
	int		j;
	char	*str;

	tmp = i;
	while (s[tmp] && check_spe_case(s[tmp]) == 0)
		tmp++;
	str = malloc(sizeof(char) * (tmp - i) + 1);
	if (!str)
		return (-1);
	j = 0;
	while (s[i] && check_spe_case(s[i]) == 0)
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
		if (s[i] == '>' || s[i] == '<'|| s[i] == '|')
			i = dup_pip_dir(tab, s, i, s[i]);
		else if (s[i] == '\'' || s[i] == '\"' )
			i = dup_quote(tab, s, i, s[i]);
		else if (s[i] && check_spe_case(s[i]) == 0)
			i = dup_str(tab, s, i);
		tab++;
		if (i == -1)
			return (free_split(first));
	}
	return (first);
}
int	main(int arc, char **argv)
{
	char  		*s;
	char		c = ' ';
	char		**tab = NULL;
	
	if (arc == 1)
		return (0);
	s = argv[1];
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