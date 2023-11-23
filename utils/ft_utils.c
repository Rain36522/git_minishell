/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:44:46 by pudry             #+#    #+#             */
/*   Updated: 2023/11/23 17:20:24 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_replace_line(char *prompt, char *s2)
{
	ft_printf("\r");
	ft_printf("\033[2K");
	ft_printf("%s%s", prompt, s2);
}

char	*ft_skip_space_quotes(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\'' || *str == '\"')
	{
		if (*str == '\'')
		{
			while (*str && *str != '\'')
				str ++;
		}
		else if (*str == '\"')
		{
			while (*str && *str != '\"')
				str ++;
		}
		str ++;
	}
	return (str);
}

static char	*ft_strjoin_free(char *str1, char *str2)
{
	str2 =ft_strjoin(str1, str2);
	free(str1);
	return (str2);
}

char	*ft_give_prompte(char **env)
{
	char	*str;
	char	*ptr;

	str = find_hostname(env);
	if (!str)
		ft_error_str(12, 1, NULL, NULL);
	str = ft_strjoin("🖥  \033[1;31m", str);
	if (!str)
		ft_error_str(12, 1, NULL, NULL);
	ptr = cwd();
	if (!str)
		ft_error_str(12, 1, NULL, NULL);
	str = ft_strjoin_free(str, " 📂 \033[0;37m");
	if (!str)
		ft_error_str(12, 1, NULL, NULL);
	str = ft_strjoin_free(str, ft_strrchr(ptr, '/') + 1);
	free(ptr);
	if (!str)
		ft_error_str(12, 1, NULL, NULL);
	str = ft_strjoin_free(str, " \033[1;37m➤ $ \033[0m");
	if (!str)
		ft_error_str(12, 1, NULL, NULL);
	return (str);
}

void	*ft_malloc(int isize, int ilength, char **array, char *str)
{
	void	*ptr;

	ptr = (void *) malloc(isize * ilength);
	if (!ptr)
		ft_error_int(12, 1, array, str);
	return (ptr);
}
