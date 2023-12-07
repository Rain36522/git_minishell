/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:55:36 by pudry             #+#    #+#             */
/*   Updated: 2023/12/07 14:13:06 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static void	*return_null(char *str)
{
	free(str);
	return (NULL);
}

char	*input_error(char *scmd)
{
	char	**array;
	char	*mem_scmd;

	mem_scmd = scmd;
	if (!scmd)
		ft_error_int(4, 1, NULL, scmd);
	else if (! *scmd)
		return (return_null(mem_scmd));
	while (*scmd && ((*scmd >= 9 && *scmd <= 14) || *scmd == 32))
		scmd ++;
	if (!*scmd)
		return (return_null(mem_scmd));
	add_history(scmd);
	if (ft_cnt_dbl_redir_str(scmd) > 0 && ft_str_end_quotes(scmd, 0) != 0)
		return (ft_error_ptr(201, 0, NULL, NULL));
	array = ft_split_minishell(scmd);
	if (!array)
		ft_error_int(12, 1, NULL, scmd);
	if (ft_check_syntax(array) == 0)
		return (ft_error_ptr(201, 0, array, NULL));
	else if (ft_check_syntax(array) == 150)
		return (ft_error_ptr(150, 0, array, NULL));
	array = ft_free_array(array);
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
	if (ft_check_syntax(array) != 1)
		return (NULL);
	lst = ft_make_lst(array);
	array = ft_free_array(array);
	return (lst);
}
