/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:02:40 by pudry             #+#    #+#             */
/*   Updated: 2023/12/06 09:28:12 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>


typedef struct s_lst
{
	char			*str;
	struct s_lst	*next;
}				t_lst;


static t_lst	*add_back(t_lst *lst, t_lst *new_lst)
{
	t_lst	*mem_lst;

	if (!lst)
		return (new_lst);
	mem_lst = lst;
	while (lst->next)
		lst = lst->next;
	lst->next = new_lst;
	return (mem_lst);
}

static t_lst	*new_lst(char *wrd)
{
	t_lst	*lst;

	lst = (t_lst *) malloc(sizeof(t_lst));
	lst->next = NULL;
	lst->str = wrd;
	return (lst);
}

static void	put_lst(t_lst *lst)
{
	t_lst	*old_lst;

	printf("array = {");
	while (lst)
	{
		printf("\"%s\"", lst->str);
		if (lst->next)
			printf(",");
		old_lst = lst;
		free(lst->str);
		lst = lst->next;
		free(old_lst);
	}
	printf("};\n");
}

static int	ft_is_end(char *str, char *str2)
{
	int		i;

	i = 0;
	if (!str || !*str || !str2 || !*str2)
		return (0);
	while (str[i] && str[i] == str2[i])
		i ++;
	return (!str[i] && !str2[i]);
}

int main(void)
{
	char	*str;
	t_lst	*lst;

	str = NULL;
	lst = NULL;
	while (ft_is_end(str, "STOP") != 1)
	{
		str = readline(">> ");
		if (ft_is_end(str, "STOP") == 0)
			lst = add_back(lst, new_lst(str));
	}
	if (lst)
		put_lst(lst);
	return (0);

}