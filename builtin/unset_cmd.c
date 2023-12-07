/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:57:36 by pudry             #+#    #+#             */
/*   Updated: 2023/12/07 16:23:31 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header_builtin.h"

static int	ft_strcmp_unset(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && s1[i] != '=')
		i ++;
	if (s1[i] == '=' && s2[i] == '\0')
		return (1);
	return (0);
}

static char	**ft_remove_env_str(char **env, int isize, int ipos, char *scmd)
{
	char	**array;
	int		k;

	k = -1;
	array = (char **) malloc(sizeof(char *) * isize);
	if (!array)
		ft_error_ptr(12, 1, env, scmd);
	array[isize + k] = NULL;
	isize --;
	while (isize >= 0)
	{
		if (isize == ipos && isize >= 1)
		{
			k ++;
			isize --;
		}
		array[isize + k] = env[isize];
		isize --;
	}
	env[ipos] = ft_free_str(env[ipos]);
	env = ft_free_ptr_ptr(env);
	return (array);
}

static char	**ft_unset(char **env, char *scmd)
{
	int	i;
	int	j;

	i = 0;
	j = 2147483647;
	while (env[i])
	{
		if (ft_strcmp_unset(env[i], scmd) == 1)
			j = i;
		i ++;
	}
	if (j >= i)
		return (env);
	return (ft_remove_env_str(env, i, j, scmd));
}

char	**unset_cmd(char **env, char **acmd)
{
	int		i;

	if (!acmd[1])
	{
		acmd = ft_free_array(acmd);
		return (env);
	}
	i = 1;
	while (acmd[i])
		env = ft_unset(env, acmd[i ++]);
	acmd = ft_free_array(acmd);
	return (env);
}
