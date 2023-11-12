/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:28:57 by pudry             #+#    #+#             */
/*   Updated: 2023/10/13 14:16:42 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		i;

	i = 1;
	if (!lst)
		return (0);
	ptr = lst;
	while (ptr)
	{
		if (!ptr->next)
			return (i);
		ptr = ptr->next;
		i ++;
	}
	return (i);
}
/*
int	main(void)
{
	int		i;
	t_list	*ptr;
	t_list	*lst;

	i = 1;
	lst = NULL;
	if (!ft_lstsize(lst))
		printf("NULL");
	ptr = ft_lstnew((char *) "a");
	lst = ptr;
	while (i > 0)
	{
		ptr->next = ft_lstnew((char *) "a");
		ptr = ptr->next;
		i --;	
	}
	printf("size : %i\n", ft_lstsize(lst));
	return (0);
}
*/
