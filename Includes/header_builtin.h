/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_builtin.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:35:26 by csil              #+#    #+#             */
/*   Updated: 2023/11/25 20:58:24 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BUILTIN_H
# define HEADER_BUILTIN_H

# include "minishell.h"

// echo command
int	dollar_gestion(char *str, int i, char **envp);
int	print_until(char *str, int i, char c, char **envp);

#endif
