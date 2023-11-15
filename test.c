/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:22:39 by pudry             #+#    #+#             */
/*   Updated: 2023/11/15 18:31:18 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int	fd;
	char *txt = "Bonjour tous le monde\nca va?";

	fd = open("test.txt", O_CREAT | O_RDWR);
	if (fd < 0)
		return (0);
	write(fd, txt, 28);
	write(fd, txt, 28);
	return (0);	
}