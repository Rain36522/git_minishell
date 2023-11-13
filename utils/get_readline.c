/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:05:47 by pudry             #+#    #+#             */
/*   Updated: 2023/11/13 14:24:01 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static void	enable_raw_mode(void)
{
	struct termios	raw;

	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

static void	disable_raw_mode(void)
{
	struct termios	raw;

	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag |= (ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

char	*get_readline(int fd)
{
	char		*ptr;
	char		buffer[2];
	int			i;
	char		*line;

	enable_raw_mode();
	buffer[1] = '\0';
	if (read(fd, buffer, 1) <= 0)
		return (NULL);
	ptr = ft_strdup(buffer);
	while (ptr && !ft_strchr(ptr, '\n') && check_up_down_key(ptr) == 0)
	{
		i = read(fd, buffer, 1);
		ft_printf("read : %s\n", buffer);
		if (i < 0)
			return (NULL);
		line = ptr;
		ptr = ft_strjoin(ptr, buffer);
		free(line);
	}
	disable_raw_mode();
	if (!ptr)
		return (NULL);
	return (ptr);
}
