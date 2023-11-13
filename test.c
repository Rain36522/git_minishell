/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:43 by pudry             #+#    #+#             */
/*   Updated: 2023/11/13 16:49:26 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"
#include <readline/history.h>

int	main(int argc, char ** argv, char **env)
{
	int		i = 0;
	char	*s;
	char	**array;

	while (i == 0)
	{
		i ++;
		s = get_readline(1);
		ft_printf("salut");
		sleep(2);
		// if (check_up_down_key(s) != 0)
		// 	ft_history();

    	// Efface la ligne
		ft_replace_line("pudry@pwd : ", "bonjour\n");
	}
}
