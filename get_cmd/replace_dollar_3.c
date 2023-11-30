/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:12:01 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/30 13:47:21 by pudry            ###   ########.fr       */
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
		free(l->str);
	l->str = new;
}

// checkup strjoin
void	check_join(t_dlist *list, char *str)
{
	if (!str)
	{
		if (list->input)
			free (list->input);
		if (list->str)
			free (list->str);
		ft_error_ptr(12, 1, NULL, NULL);
	}
}
