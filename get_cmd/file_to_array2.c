/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_array2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:13:08 by pudry             #+#    #+#             */
/*   Updated: 2023/12/07 17:34:37 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static char	*ft_make_cmd(char *scmd, t_data *data)
{
	scmd = replace_dollar(scmd, 0, data);
	return (scmd);
}

t_acmd	*treat_input(t_acmd *acmd_data, t_data *data)
{
	int		i;

	i = 1;
	if (acmd_data->isize == 1)
		acmd_data->array[0] = ft_make_cmd(acmd_data->array[0], data);
	while (acmd_data->isize > 1 && acmd_data->array[i + 1])
	{
		acmd_data->array[i] = ft_make_cmd(acmd_data->array[i], data);
		i ++;
	}
	return (acmd_data);
}
