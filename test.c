/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:43 by pudry             #+#    #+#             */
/*   Updated: 2023/11/13 18:52:08 by pudry            ###   ########.fr       */
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
	while (1)
	{
		i ++;
		scmd = get_cmd(1);
		if (!scmd)
			return (0);
		// acmd = ft_split_quotes(scmd);
		// i = 0;
		// while (acmd[i] && j == 0)
		// 	j = ft_check_cmd(acmd[i]);
		// if (j != 0)
		// 	return(ft_error_int(j));

	}
}
