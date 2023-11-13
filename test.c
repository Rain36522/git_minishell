/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:43 by pudry             #+#    #+#             */
/*   Updated: 2023/11/13 14:20:25 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"

int	main(int argc, char ** argv, char **env)
{
	int		i = 0;
	char	*s;

	while (i ++ < 5)
	{
		s = get_readline(1);
		ft_printf("str : %s\n", s);
		if (check_up_down_key(s) != 0)
			ft_putstr_fd("key pressed\n", 1);
	}
}
