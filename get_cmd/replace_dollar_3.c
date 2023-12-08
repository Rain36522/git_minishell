/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:12:01 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/08 09:33:19 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	join_char(t_dlist *l, char c)
{
	int		len;
	int		i;
	char	*new;

	len = 0;
	if (l->str)
		len = ft_strlen(l->str);
	i = 0;
	new = malloc(sizeof(char) * len + 2);
	if (!new)
	{
		free (l->input);
		l->input = NULL;
		ft_error_ptr(12, 1, NULL, l->str);
	}
	while (l->str && l->str[i])
	{
		new[i] = l->str[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	if (l->str)
		l->str = ft_free_str(l->str);
	l->str = new;
}

// checkup strjoin
void	check_join(t_dlist *list, char *str)
{
	if (!str)
	{
		if (list->input)
		{
			free (list->input);
			list->input = NULL;
		}
		if (list->str)
		{
			free (list->str);
			list->str = NULL;
		}
		ft_error_ptr(12, 1, NULL, NULL);
	}
}

void	if_question_mark(t_dlist *l, t_data *data)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_itoa(data->imem_exit);
	while (tmp[i])
	{
		l->str = dollar_join_char(l->str, tmp[i]);
		i++;
	}
	tmp = ft_free_str(tmp);
	l->i++;
}

char	*dollar_join_char(char *str, char c)
{
	int		len;
	int		i;
	char	*new;

	len = 0;
	if (str)
		len = ft_strlen(str);
	i = 0;
	new = malloc(sizeof(char) * len + 2);
	if (!new)
		ft_error_ptr(12, 1, NULL, str);
	while (str && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	if (str)
		free(str);
	str = NULL;
	return (new);
}
