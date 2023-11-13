/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:43 by pudry             #+#    #+#             */
/*   Updated: 2023/11/13 09:44:13 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "gnl/get_next_line.h"
#include <stdio.h>
#include <readline/readline.h>

int	main(void)
{
	int		i = 0;
	char	*s;

	while (i ++ < 5)
	{
		ft_printf("minishell@pudry : ");
		s = get_next_line(1);
		ft_printf("line : %s\n", s);
	}
}
