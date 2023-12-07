/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:26:03 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/06 18:03:31 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

// on est dans une double donc on carry le $ quoi quil ce passe
void	state_2(t_dlist *l, t_data *data)
{
	while (l->input[l->i] && l->input[l->i] != '\"')
	{
		if (l->input[l->i] == '$' && print_dollar(l->input[l->i + 1]) == 0)
			join_dollar(l, data);
		else
		{
			join_char(l, l->input[l->i]);
			check_join(l, l->str);
			l->i++;
		}
	}
	if (l->input[l->i] && l->input[l->i] == '\"')
	{
		join_char(l, l->input[l->i]);
		check_join(l, l->str);
		l->i++;
	}	
	l->state = 0;
}

int	print_dollar(char c)
{
	if (c == 32)
		return (1);
	else if (c == 9)
		return (1);
	else if (c == '\0')
		return (1);
	else if (c == '?')
		return (0);
	else
		return (0);
}

void	relais_state_1(t_dlist *l)
{
	join_char(l, l->input[l->i]);
	check_join(l, l->str);
	l->i++;
	state_1(l);
}

// were not anymore in double or single quote
// take the count with qdouble if were in a double
// or a single so we know what we hae to do
void	finish_dollar(t_dlist *l, t_data *data)
{
	while (l->input[l->i])
	{
		if (l->input[l->i] && l->input[l->i] == '\'')
		{
			relais_state_1(l);
		}
		else if (l->input[l->i] && l->input[l->i] == '\"')
		{
			join_char(l, l->input[l->i]);
			check_join(l, l->str);
			l->i++;
			state_2(l, data);
		}
		else if (l->input[l->i] && l->input[l->i] == '$'
			&& print_dollar(l->input[l->i + 1]) == 0)
			join_dollar(l, data);
		else
		{
			join_char(l, l->input[l->i]);
			check_join(l, l->str);
			l->i++;
		}
	}
}

// est-ce qu'on est dans un single ou dans un double
char	*replace_dollar(char *str, int state, t_data *data)
{
	t_dlist	list;

	list_init(&list, str, state);
	if (state == 1)
	{
		state_1(&list);
		state = 0;
	}
	if (state == 2)
	{
		state_2(&list, data);
		state = 0;
	}
	finish_dollar(&list, data);
	str = ft_free_str(str);
	return (list.str);
}

/*
	dollar qui s'annule si sp tab ou \0 derrièe -> tu le laisse
	sinon tu skip tout
*/
// int main(int argc, char **argv, char **env)
// {
// 	(void) argc;
// 	(void) argv;

// 	// si ça fini par un \0 : ca par en couille
// 	char *str = "la befana $USER    ";
// 	replace_dollar(str, 2, env);
// 	return (0);
// }
