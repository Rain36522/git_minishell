/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:03:27 by pudry             #+#    #+#             */
/*   Updated: 2023/11/27 08:05:47 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_redir(int fd_in, int fd_out)
{
	char	*buf;
	int		i;
	int		j;

	buf = ft_malloc(BUFFER_SIZE + 1);
	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE)
	{
		if (i < 0)
			break;
		i = read(fd_in, buf, BUFFER_SIZE);
		i = write(fd_out, buf, i);
		j = 0;
		while (j < BUFFER_SIZE)
			buf[j ++] = '\0';
	}
	free(buf);
	if (i < 0)
		exit(23);
	exit(0);
}
