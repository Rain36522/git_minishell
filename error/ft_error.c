/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:52:09 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/29 14:43:38 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

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

void	*ft_error_ptr(int icode, int iexit, char **array, char *str)
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

void	*ft_error_child(int icode, char **array, char *str, char *str2)
{
	if (array)
		ft_free_array(array);
	if (str)
		free(str);
	if (str2)
		free(str2);
	if (icode <= 130 && icode != 127)
		exit(icode);
	return (NULL);
}