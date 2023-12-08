/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:10:54 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/08 09:33:11 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

// initialise the list
void	list_init(t_dlist *list, char *str, int state)
{
	list->i = 0;
	list->input = str;
	list->qdouble = 0;
	list->state = state;
	list->str = NULL;
}

// loop join until '\'' or the end
void	state_1(t_dlist *l)
{
	while (l->input[l->i] && l->input[l->i] != '\'')
	{
		join_char(l, l->input[l->i]);
		check_join(l, l->str);
		l->i++;
	}
	if (l->input[l->i] && l->input[l->i] == '\'')
	{
		join_char(l, l->input[l->i]);
		check_join(l, l->str);
		l->i++;
	}
}

// return the first occurence of the equal sign
int	found_equal(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

void	join_var_to_str(t_dlist *l, char **env, int equal, int i)
{
	if (!l->str)
		l->str = ft_strdup(env[i] + (equal + 1));
	else
		l->str = ft_strjoin_free(l->str, env[i] + (equal + 1));
	if (!l->str)
	{
		free (l->input);
		l->input = NULL;
		ft_error_ptr(12, 1, NULL, l->str);
	}
	l->i += (equal);
}

// return the index until '=' in the env
// found the variable attibuate to
// if the variable dosent exist : skip it
void	join_dollar(t_dlist *l, t_data *data)
{
	int		equal;
	int		i;

	i = 0;
	if (l->input[l->i] && l->input[l->i] == '$')
		l->i++;
	if (l->input[l->i] && l->input[l->i] == '?')
		if_question_mark(l, data);
	else
	{
		while (data->env[i])
		{
			equal = found_equal(data->env[i]);
			if (ft_strncmp(l->input + l->i, data->env[i], equal) == 0)
			{
				join_var_to_str(l, data->env, equal, i);
				return ;
			}
			i++;
		}
	}
	while (l->input[l->i] && print_dollar(l->input[l->i]) == 0)
		l->i++;
}
