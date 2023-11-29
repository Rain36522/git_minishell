/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:57:36 by pudry             #+#    #+#             */
/*   Updated: 2023/11/28 17:07:24 by pudry            ###   ########.fr       */
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
		ft_error(12, 1, NULL, NULL);
	array[ipos] = ptr;
	free(str);
	return (array);
}

char	**export_cmd(char **env, char *scmd)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	while (env[i] && ft_strcmp_egal(env[i], scmd) != 1)
		i ++;
	if (env[i])
		return (ft_replace_str_array(env, i));
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
		ft_error_int(12, 1, NULL, scmd);
	ft_free_array(env);
	free(scmd);
	return (array);
}

