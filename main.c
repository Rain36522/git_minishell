/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:43 by pudry             #+#    #+#             */
/*   Updated: 2023/11/21 15:30:51 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"
#include <readline/history.h>
#include <stdio.h>

int	main(int argc, char ** argv, char **env)
{
	int		i;
	int		j;
	char	**acmd;
	char	*prompt;

	argc += 0;
	argv += 0;
	prompt = ft_give_prompte(env);
	j = 0;
	i = 0;
	while (i == 0)
	{
		acmd = get_cmd("pudry@42 : ");
		i ++;
	}
	return (0);
}
