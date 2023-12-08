/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:57:36 by pudry             #+#    #+#             */
/*   Updated: 2023/12/08 09:21:25 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header_builtin.h"

char	**ft_change_env(char *str, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strcmp_egal(env[i], str))
		{
			free(env[i]);
			env[i] = str;
			return (env);
		}
		i ++;
	}
	env[i] = str;
	return (env);
}

static char	*ft_put_to_egal(char *str)
{
	while (*str)
	{
		ft_putchar_fd(*str, 1);
		if (*str == '=')
			return (str + 1);
		str ++;
	}
	return (NULL);
}

char	**ft_put_export(char **array, char **afree)
{
	int		i;
	char	*ptr;

	i = 0;
	while (array[i])
	{
		ft_printf("declare -x ");
		ptr = ft_put_to_egal(array[i ++]);
		if (ptr)
			ft_printf("\"%s\"", ptr);
		ft_putchar_fd('\n', 1);
	}
	ft_free_array(afree);
	return (array);
}
