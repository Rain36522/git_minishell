/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:57:36 by pudry             #+#    #+#             */
/*   Updated: 2023/12/04 15:46:57 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header_builtin.h"

int	ft_strcmp_egal(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && s1[i] != '=')
		i ++;
	if ((s1[i] == '=' && s2[i] == '=') || (!s1 && !s2))
		return (1);
	return (0);
}

static int	ft_str_is_in_array(char *s1, char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strcmp_egal(s1, array[i]))
			return (1);
		i ++;
	}
	return (0);
}

static int	ft_check_arg(char **acmd)
{
	int	i;
	int	j;

	i = 1;
	while (acmd[i])
	{
		j = 0;
		while (acmd[i][j] && ft_isdigit(acmd[i][j]))
			j ++;
		if(!acmd[i][j])
			return (ft_error_int(201, 0, acmd, NULL));
		i ++;
	}
	return (i);
}

static char	**ft_cpy_array_big_size(char **env, int iargs)
{
	char	**array;
	int		j;
	int		isize;

	j = 0;
	while (env[j])
		j ++;
	isize = j + iargs - 1;
	array = (char **) malloc(sizeof(char *) * (isize + 1));
	if (!array)
		return (ft_error_ptr(150, 0, env, NULL));
	j = 0;
	while (env[j])
	{
		array[j] = env[j];
		j ++;
	}
	free(env);
	while (j <= isize)
		array[j ++] = NULL;
	return (array);
}

char	**export_cmd(char **env, char *scmd)
{
	char	**acmd;
	int		i;
	int		j;

	acmd = ft_split_minishell(scmd);
	free(scmd);
	if (!acmd)
		ft_error_ptr(12, 1, env, NULL);
	i = ft_check_arg(acmd);
	if (!i)
		return (env);
	if (i == 1)
		return (ft_put_export(env, acmd));
	j = 1;
	while (acmd[j])
		i -= ft_str_is_in_array(acmd[j ++], env);
	env = ft_cpy_array_big_size(env, i);
	if (!env)
		ft_error_int(12, 1, acmd, NULL);
	i = 1;
	while(acmd[i])
		env = ft_change_env(acmd[i ++], env);
	free(*acmd);
	free(acmd);
	return (env);
}


