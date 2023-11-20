/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:43 by pudry             #+#    #+#             */
/*   Updated: 2023/11/20 14:24:54 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"
#include <readline/history.h>

int	main(int argc, char ** argv, char **env)
{
	int		i;
	int		j;
	char	**acmd;

	j = 0;
	i = 0;
	while (i == 0)
	{
		acmd = get_cmd("pudry@42 : ");
		if (!acmd)
			return (0);
		i ++;
	}
}
