/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:43 by pudry             #+#    #+#             */
/*   Updated: 2023/11/14 11:02:44 by pudry            ###   ########.fr       */
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
	while (i <= 2)
	{
		scmd = get_cmd("pudry@42 : ");
		ft_printf("cmd : %s\n", scmd);
		
		if (!scmd)
			return (0);
		if (check_up_down_key(scmd) == 1)
			ft_printf("\n");
		if (check_up_down_key(scmd) != 0)
			ft_printf("key pressed\n");
		add_history(scmd);
		free(scmd);
		i ++;
		// acmd = ft_split_quotes(scmd);
		// i = 0;
		// while (acmd[i] && j == 0)
		// 	j = ft_check_cmd(acmd[i]);
		// if (j != 0)
		// 	return(ft_error_int(j));
	}
}
