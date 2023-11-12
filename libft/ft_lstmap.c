/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:29:04 by pudry             #+#    #+#             */
/*   Updated: 2023/10/19 08:55:12 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstcreate(t_list *lst, void *(*f)(void *))
{
	t_list	*ptr;

	ptr = (t_list *) malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = f(lst->content);
	return (ptr);
}

static t_list	*ft_malloc_empty(t_list **lst, void (*del) (void *))
{
	if (lst)
		ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *))
{
	t_list	*ptr;
	t_list	*new_lst;
	t_list	*old_lst;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstcreate(lst, f);
	if (!new_lst)
		return (NULL);
	old_lst = lst->next;
	ptr = new_lst;
	while (old_lst)
	{
		ptr->next = 0;
		tmp = ft_lstcreate(old_lst, f);
		if (!tmp)
			return (ft_malloc_empty(&new_lst, del));
		ptr->next = tmp;
		ptr = ptr->next;
		old_lst = old_lst->next;
	}
	ptr->next = NULL;
	return (new_lst);
}
/*
void	del(void *content)
{
	free(content);
}
void	*f(void *chr)
{

	chr ++;
	return (chr);
}

void	ft_print(t_list *ptr)
{
	int	i;

	i = 1;
	while (ptr)
	{
		printf("lst %i : %s\n", i, (char *)ptr->content);
		ptr = ptr->next;
		i ++;
	}	
}

int	main(void)
{
	int		i;
	t_list	*ptr;
	t_list	*lst;
	char	c[] = "a";

	i = 0;
	lst = NULL;
	ptr = ft_lstnew((char *) "a");
	lst = ptr;
	while (i < 5)
	{
		c[0] ++;
		ptr->next = ft_lstnew(c);
		printf("char : %s\n", c);
		ptr = ptr->next;
		i ++;	
	}
	printf("size : %i\n", ft_lstsize(lst));
	ptr = ft_lstmap(lst, f, del);
	printf("size : %i\n", ft_lstsize(ptr));
	ft_print(ptr);
	
	return (0);
}
*/