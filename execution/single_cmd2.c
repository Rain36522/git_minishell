/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:28:16 by pudry             #+#    #+#             */
/*   Updated: 2023/12/08 09:28:45 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	no_final_path(char **tab, char **paths, char *final_path)
{
	ft_putstr_fd(tab[0], 2);
	ft_free_array(paths);
	ft_error_int(127, 0, tab, final_path);
}
