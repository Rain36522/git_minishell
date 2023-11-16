/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:22:39 by pudry             #+#    #+#             */
/*   Updated: 2023/11/16 09:10:48 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int	fd;
	char *txt = "Bonjour tous le mondeca va?";

	fd = open("a.txt", O_CREAT | O_RDWR | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		return (0);
	write(fd, txt, 28);
	write(fd, "\n", 1);
	write(fd, txt, 28);
	close(fd);
	return (0);	
}