/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:52:09 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/21 09:55:57 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i ++]);
	}
	free(array);
}

int	ft_error_int(int icode, int iexit, char **array, char *str)
{
	if (array)
		ft_free_array(array);
	if (str)
		free(str);
	ft_error_msg(icode);
	if (iexit == 1)
		exit(icode);
	return (0);
}

char	*ft_error_str(int icode, int iexit, char **array, char *str)
{
	if (array)
		ft_free_array(array);
	if (str)
		free(str);
	ft_error_msg(icode);
	if (iexit == 1)
		exit(icode);
	return (NULL);
}

char	**ft_error_array(int icode, int iexit, char **array, char *str)
{
	if (array)
		ft_free_array(array);
	if (str)
		free(str);
	ft_error_msg(icode);
	if (iexit == 1)
		exit(icode);
	return (NULL);
}

