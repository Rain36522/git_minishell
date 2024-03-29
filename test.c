/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:22:39 by pudry             #+#    #+#             */
/*   Updated: 2023/11/22 15:25:50 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		i = 1;

#include "Includes/minishell.h"
#include <stdio.h>
# include <signal.h>

void	sig_ctrl_c()
{
	printf("signal\n");
	write(0, "\n", 1);
	i = 0;
}


int	main(void)
{
	char	*str;

	signal(SIGINT, sig_ctrl_c);

	while (i)
	{
		str = readline("> ");
		printf("str : %s\n", str);
	}
	printf("function exit\n");
	return (0);	
}