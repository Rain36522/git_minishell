/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:33:17 by pudry             #+#    #+#             */
/*   Updated: 2023/12/03 17:39:52 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*ft_free_str(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

char	**ft_free_ptr_ptr(char **ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

int	ft_array_len(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		i ++;
	return (i);
}
