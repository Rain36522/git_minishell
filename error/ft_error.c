/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:52:09 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/08 09:32:06 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	ft_error_int(int icode, int iexit, char **array, char *str)
{
	if (icode == 4)
		icode = 0;
	if (array)
		array = ft_free_array(array);
	if (str)
		str = ft_free_str(str);
	ft_error_msg(icode);
	if (iexit == 1)
		exit(icode);
	return (0);
}

void	*ft_error_ptr(int icode, int iexit, char **array, char *str)
{
	if (icode == 4)
		icode = 0;
	if (array)
		ft_free_array(array);
	if (str)
		str = ft_free_str(str);
	ft_error_msg(icode);
	if (iexit == 1)
		exit(icode);
	return (NULL);
}

void	*ft_error_child(int icode, char **array, char *str, char *str2)
{
	if (array)
		ft_free_array(array);
	if (str)
		str = ft_free_str(str);
	str = NULL;
	if (str2)
		str2 = ft_free_str(str2);
	if (icode <= 130 && icode != 127)
		exit(icode);
	return (NULL);
}

void	*ft_error_get_cmd(int icode, char **env, char *str, char *str2)
{
	if (env && icode <= 130 && icode != 127)
		ft_free_array(env);
	if (str)
		str = ft_free_str(str);
	str = NULL;
	if (str2)
		str2 = ft_free_str(str2);
	if (icode <= 130 && icode != 127)
		exit(icode);
	return (NULL);
}
