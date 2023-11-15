/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:44 by pudry             #+#    #+#             */
/*   Updated: 2023/11/15 18:56:22 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static char *ft_first_filen_name(void)
{
	char	*str;

	str = ft_itoa(getpid());
	if (!str)
		return (NULL);
	str = ft_strjoin(str, "_a.tmp");
	return (str);
}

char	*ft_name_file(char *str)
{
	char	*pid;
	int		i;

	if (!str)
		return (ft_first_filen_name());
	i = 0;
	str = ft_strdup(str);
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '_')
		i ++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	str[i + 1] ++;
	return (str);
}
static int	ft_create_file(char *filename, char *wrd)
{
	int		fd;
	char	*ptr;
	int		isize;
	char	*scmd;

	fd = open(filename, O_CREAT | O_RDWR);
	ft_printf("opening_file fd : %i\n", fd);
	if (fd < 0)
		return (fd);
	ft_printf("file open\n");
	isize = ft_strlen(wrd);
	scmd = readline("$ > ");
	while (ft_strncmp(scmd, wrd, isize) != 0)
	{
		ft_putstr_fd(scmd, fd);
		ft_putstr_fd("\n", fd);
		scmd = readline("$ > ");
	}
	return (close(fd));
	
}


int	ft_write_file(t_incmd *lst)
{
	int	i;

	i = 0;
	while (i >= 0 && lst)
	{
		i = ft_create_file(lst->filename, lst->wrd);
		lst =lst->next;
	}
	return (i);
}
