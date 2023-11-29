/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:55:36 by pudry             #+#    #+#             */
/*   Updated: 2023/11/29 14:42:39 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*input_error(char *scmd)
{
	char	**array;

	if (!scmd)
		ft_error_int(4, 1, NULL, scmd);
	else if (! *scmd)
		return (NULL);
	add_history(scmd);
	if (ft_cnt_dbl_redir_str(scmd) > 0 && ft_str_end_quotes(scmd, 0) != 0)
		return (ft_error_ptr(201, 1, NULL, NULL));
	array = ft_split_minishell(scmd);
	if (!array)
		ft_error_int(12, 1, NULL, scmd);
	if (ft_check_syntax(array) == 0)
		return (ft_error_ptr(201, 1, array, NULL));
	return (scmd);	
}

t_incmd	*redir_lst(char *scmd)
{
	t_incmd	*lst;
	char	**array;

	if (!(ft_str_end_quotes(scmd, 0) == 0 && ft_cnt_dbl_redir_str(scmd) > 0))
		return (NULL);
	array = ft_split_minishell(scmd);
	if (!array)
		ft_error_int(12, 1, NULL, scmd);
	if (ft_check_syntax(array) == 0)
		return (NULL);
	lst = ft_make_lst(array);
	ft_free_array(array);
	return (lst);
}