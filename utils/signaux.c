/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:50:54 by pudry             #+#    #+#             */
/*   Updated: 2023/11/29 16:14:43 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include <readline/readline.h>

void	parent_signal(int isignal)
{
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	return;
}

void	child_signal(int isignal)
{
	exit(127);
}