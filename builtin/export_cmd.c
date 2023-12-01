/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:57:36 by pudry             #+#    #+#             */
/*   Updated: 2023/12/01 15:34:22 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header_builtin.h"

static int	ft_strcmp_egal(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && s1[i] != '=')
		i ++;
	if (s1[i] == '=' && s2[i] == '=')
		return (1);
	return (0);
}

static char	**ft_replace_string_array(char **array, char *str, int ipos)
{
	char	*ptr;

	free(array[ipos]);
	ptr = ft_strdup(str);
	if (!ptr)
		ft_error_int(12, 1, NULL, NULL);
	array[ipos] = ptr;
	free(str);
	return (array);
}

static char	**strdup_array_add_str(int i, char *scmd, char **env)
{
	char	**array;
	int		j;

	j = 0;
	array = (char **) malloc(sizeof(char *) * i + 2);
	if (!array)
		ft_error_int(12, 1, NULL, scmd);
	array[i + 1] = NULL;
	while (j < i)
	{
		env[j] = array[j];
		j ++;
	}
	array[i] = ft_strdup(scmd);
	if (!array[i])
		ft_error_int(12, 1, array, scmd);
	ft_free_array(env);
	free(scmd);
	return (array);
}

static char	**ft_export(char **env, char *scmd)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ft_strchr(scmd, '='))
		j ++;
	while (scmd[i] != '=' && ft_isdigit(scmd[i]) && !j)
		i ++;
	if (scmd[i] == '=' && !j)
		j ++;
	if (j)
		return (ft_error_ptr(22, 0, env, scmd));
	i = 0;
	while (env[i] && ft_strcmp_egal(env[i], scmd) != 1)
		i ++;
	if (env[i])
		return (ft_replace_string_array(env, scmd, i));
	env = strdup_array_add_str(i, scmd, env);
	return (env);
}

char	**export_cmd(char **env, char *scmd)
{
	int		i;
	char	**acmd;

	i = 0;
	acmd = ft_split_minishell(scmd);
	free(scmd);
	if (!acmd)
		ft_error_int(12, 1, env, NULL);
	while (acmd[i])
		i ++;
	if (i == 1)
	{
		ft_printf("101\n");
		ft_free_array(acmd);
		ft_put_export(env);
		return (env);
	}
	i = 1;
	while (acmd[i])
		env = ft_export(env, acmd[i]);
	ft_free_array(acmd);
	return (env);

}

