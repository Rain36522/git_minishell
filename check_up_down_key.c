/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_up_down_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:48:15 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/13 13:28:25 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"

// Recherche si to_find est present dans str
// return (1) si present else return (0);
static int	find_str(char *str, char *to_find, int len)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			if (strncmp(str + i, to_find, len) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

// fonction qui va checker si la touche fleche haut ou fleche bas
// Ont ete saisies : return (1) si oui else : return (0);
int	check_up_down_key(char *str)
{
	if (find_str(str, "\e[A", 3) == 1)
		return (1);
	else if (find_str(str, "\e[B", 3) == 1)
		return (1);
	else if (find_str(str, "^[OB", ft_strlen("^[OB")) == 1)
		return (1);
	else if (find_str(str, "^[OA", ft_strlen("^[OA")) == 1)
		return (1);
	return (0);
}

/*int	main(void)
{
	printf ("%d\n", check_up_down_key("la befana viene\e[ di notte"));
}*/
