/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_quotes_to_wrds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:25:44 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/16 09:46:44 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

// count the nbr of valid char that we want to dup
int	len_delete_quotes(char *str, int len, int i)
{
	char	quote;

	quote = '0';
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"' && quote == '0')
		{
			quote = str[i];
			i++;
			while (str[i] && str[i] != quote)
			{
				i++;
				len++;
			}
			if (str[i] && str[i] == quote)
				i++;
			quote = '0';
		}
		else
		{
			i++;
			len++;
		}
	}	
	return (len);
}

char	*cpy_pste_clean_line(char *str, char *dup, int i, int j)
{
	char	quote;

	quote = '0';
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"' && quote == '0')
		{
			quote = str[i];
			i++;
			while (str[i] && str[i] != quote)
				dup[j++] = str[i++];
			if (str[i] && str[i] == quote)
				i++;
			quote = '0';
		}
		else if (str[i])
			dup[j++] = str[i++];
	}
	dup[j] = '\0';
	return (dup);
}

// supress all of the extra quotes
// and return a clean string
char	*delete_quotes(char *str, int i, int len, char quote)
{
	char	*dup;

	len = len_delete_quotes(str, 0, 0);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	dup = cpy_pste_clean_line(str, dup, 0, 0);
	return (dup);
}

// check si il y a des quotes a supp
int	there_is_quotes(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

char	**from_quotes_to_wrds(char **tab)
{
	int		i;
	int		j;
	char	tmp;
	char	*s_tmp;

	i = 0;
	j = 0;
	tmp = '0';
	while (tab[i])
	{
		if (there_is_quotes(tab[i]) == 1)
		{
			s_tmp = tab[i];
			tab[i] = delete_quotes(tab[i], 0, 0, tmp);
			free(s_tmp);
		}
		i++;
	}
	return (tab);
}

/*int	main(int argc, char **argv)
{
	char	**tab = NULL;
	int		i = 0;

	(void)	argc;
	tab = from_quotes_to_wrds(argv + 1);
	while (tab[i])
	{
		printf ("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	printf ("%s\n", tab[i]);
	free(tab[i]);
	return (0);
}*/
