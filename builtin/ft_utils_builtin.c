/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:51:57 by pudry             #+#    #+#             */
/*   Updated: 2023/12/07 09:18:34 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header_builtin.h"

// this function take argv[0] from builtin_aformatting.
int	check_builtin(char *str, int iexit)
{
	if (!str)
		ft_error_int(127, iexit, NULL, NULL);
	else if (!ft_strncmp(str, "echo ", 5) || !ft_strncmp(str, "echo", 5))
		return (1);
	else if (!ft_strncmp(str, "cd ", 3) || !ft_strncmp(str, "cd", 3))
		return (2);
	else if (!ft_strncmp(str, "env", 4))
		return (3);
	else if (!ft_strncmp(str, "export ", 7) || !ft_strncmp(str, "export", 7))
		return (4);
	else if (ft_strncmp(str, "unset ", 6) || !ft_strncmp(str, "unset", 6))
		return (5);
	else if (!ft_strncmp(str, "exit ", 5) || !ft_strncmp(str, "exit", 5))
		return (6);
	else
		return (0);
}

char	*builtin_strformatting(char **array)
{
	char	*str;
	int		i;

	i = 2;
	str = array[1];
	while (array[i] && str)
		str = ft_strjoin_free(str, array[i ++]);
	free(array[0]);
	array = ft_free_ptr_ptr(array);
	if (!str)
		return (NULL);
	return (str);
}

char	**builtin_aformatting(char *str)
{
	char	**array;
	int		i;

	array = ft_split_minishell(str);
	if (!array)
		return (NULL);
	while (array[i])
	{
		array[i] = from_quotes_to_wrds(array[i]);
		if (!array[i])
		{
			i ++;
			while (array[i])
				free(array[i ++]);
			array = ft_free_array(array);
			return (NULL);
		}
	}
	return (array);
}
