/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcampita <mcampita@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:38:31 by mcampita          #+#    #+#             */
/*   Updated: 2024/11/16 19:08:59 by mcampita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1u];
	char		*holder;
	int			bytes;

	if (fd < 0)
		return (NULL);
	holder = NULL;
	//bytes = 0;
	/*
	while (!holder || !gnl_strchr(holder, '\n'))
	{
		if (!*buff)
		{
			bytes = read(fd, buff, BUFFER_SIZE);
			if (bytes == 0)
				return (holder);
			if (bytes < 0 && holder)
				free(holder);
			if (bytes < 0)
				return (NULL);
			buff[bytes] = '\0';
		}
		holder = appendbuff(holder, buff);
	}
	*/
	while (1)
	{
		if (!*buff)
		{
			bytes = read(fd, buff, BUFFER_SIZE);
			if (bytes == 0)
				return (holder);
			if (bytes < 0)
			{
				if (holder)
					free(holder);
				return (NULL);
			}
			buff[bytes] = '\0';
		}
		holder = appendbuff(holder, buff);
		if (gnl_strchr(holder, '\n'))
			break;
		*buff = '\0';
    }
	return (holder);
}
