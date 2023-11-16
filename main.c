/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:43 by pudry             #+#    #+#             */
/*   Updated: 2023/11/16 09:35:33 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"
#include <readline/history.h>

int	main(int argc, char ** argv, char **env)
{
	int		i;
	int		j;
	char	*scmd;
	char	**acmd;

	j = 0;
	i = 0;
	while (i == 0)
	{
		scmd = get_cmd("pudry@42 : ");
		if (!scmd)
			return (0);
		ft_printf("cmd1 : %s\n", scmd);
		free(scmd);
		i ++;
		//free(scmd);
		// while (acmd[i] && j == 0)
		// 	j = ft_check_cmd(acmd[i]);
		// if (j != 0)
		// 	return(ft_error_int(j));
	}
}
