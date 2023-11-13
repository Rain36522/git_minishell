/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:05:47 by pudry             #+#    #+#             */
/*   Updated: 2023/11/13 18:22:32 by pudry            ###   ########.fr       */
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

static char	*ft_readline(int fd)
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
	ft_printf("%s", buffer);
	while (ptr && !ft_strchr(ptr, '\n') && check_up_down_key(ptr) == 0)
	{
		i = read(fd, buffer, 1);
		if (i < 0)
			return (NULL);
		line = ptr;
		ptr = ft_strjoin(ptr, buffer);
		ft_printf("%s", buffer);
		free(line);
	}
	disable_raw_mode();
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*get_cmd(int fd)
{
	char	*ptr;
	char	*ptr2;
	char	*scmd;
	int		i;

	scmd = ft_readline(fd);
	i = ft_quotes(ptr, 0);
	while (i != 0 && scmd)
	{
		ft_printf("=>");
		ptr = scmd;
		ptr2 = ft_readline(fd);
		i = ft_quotes(ptr2, i);
		scmd = ft_strjoin(ptr, ptr2);
		free(ptr);
		free(ptr2);
	}
	if (!scmd)
		return (NULL);
	return (scmd);
}