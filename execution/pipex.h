/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:31:10 by csil              #+#    #+#             */
/*   Updated: 2023/12/08 09:34:37 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Includes/minishell.h"

# include <stdio.h>
# include <fcntl.h>

# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		cmd_nbr;
	int		pipe_nbr;
	int		input;
	int		output;
	int		index;
	int		exit_value;
	int		*pipe;
	pid_t	*pid_array;
	char	*env_path;
	char	**cmd_path;
	char	**cmd_args;
	char	*cmd;
	char	**argv;
	char	**envp;
	pid_t	pid;
}				t_pipex;

# ifndef S_DATA
#  define S_DATA

typedef struct s_data
{
	char			**env;
	pid_t			pid;
	int				iexit;
	int				imem_exit;
}				t_data;
# endif

// Process
void	child_process(char **argv, t_data *data, t_pipex l);
void	ft_dup2(t_pipex *list, int input, int output);

// Exit && error gestion
void	free_tab(char **tab);
void	wrong_args_number(void);
void	close_all_pipes(t_pipex *list);
void	cmd_not_found(t_pipex *list);
void	free_all_exit(t_pipex *list, int nbr);

// Path creation
char	*create_final_path(t_pipex *list, char **paths, char *arg);
char	*env_path(char **envp);

// REDIRECTIONS
void	ft_make_redir(char **array);
// if not execve
// void	builtin_checker(t_pipex *list, char *str, char **tab_cmd);

// Main process
void	set_outfile(int argc, char **argv, t_pipex *list);
void	create_pipes(t_pipex *list);
int		pipex(int argc, char **argv, t_data *data);
void	builtin_checker(t_pipex *list, char **envp);
void	wait_child_process(t_pipex *list, t_data *data);

#endif
