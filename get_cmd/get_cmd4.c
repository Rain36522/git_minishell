/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:44 by pudry             #+#    #+#             */
/*   Updated: 2023/11/15 18:22:08 by pudry            ###   ########.fr       */
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
int	ft_create_file(char *filename)
{
	
}


int	ft_write_file(t_incmd *lst)
{
	char *ptr;
}
