/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:50:25 by pudry             #+#    #+#             */
/*   Updated: 2023/10/16 12:42:43 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_skipchr(const char *s1, char c)
{
	while (*s1 && *s1 == c)
		s1 ++;
	return (s1);
}

static int	ft_nstr(char const *s1, char c)
{
	int		iresult;

	iresult = 0;
	while (*s1)
	{
		while (*s1 == c)
			s1 ++;
		if (*s1 != c && *s1)
		{
			iresult ++;
			while (*s1 && *s1 != c)
				s1 ++;
		}
	}
	return (iresult);
}

static int	ft_strsize(char const *s1, char c)
{
	int	i;

	i = 0;
	while (*s1 && *s1 != c)
	{
		i ++;
		s1 ++;
	}
	return (i);
}

static char	**ft_str_error(int i, char **array)
{
	i --;
	while (i >= 0)
		free(array[i--]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s1, char c)
{
	int		i;
	int		j;
	int		k;
	char	**array;

	i = 0;
	k = ft_nstr(s1, c);
	array = (char **) malloc(sizeof(char *) * (k + 1));
	if (! array)
		return (NULL);
	array[k] = NULL;
	s1 = ft_skipchr(s1, c);
	while (*s1 && i <= k)
	{
		array[i] = (char *) malloc(ft_strsize(s1, c) + 1);
		if (!array[i])
			return (ft_str_error(i, array));
		array[i][ft_strsize(s1, c)] = '\0';
		j = 0;
		while (*s1 != '\0' && *s1 != c)
			array[i][j ++] = *s1 ++;
		i ++;
		s1 = ft_skipchr(s1, c);
	}
	return (array);
}
/*
int	main(void)
{
	ft_split("hello!", ' ');
	return (0);
}*/