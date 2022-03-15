/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 08:41:47 by asaffroy          #+#    #+#             */
/*   Updated: 2021/11/11 08:41:47 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_chunk_of_fd(int fd, char *bigstr)
{
	char	*buffer;
	int		nbrread;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nbrread = 1;
	while (!ft_strchrmod(bigstr, '\n') && nbrread != 0)
	{
		nbrread = read(fd, buffer, BUFFER_SIZE);
		if (nbrread == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbrread] = '\0';
		bigstr = ft_strjoincustom(bigstr, buffer);
	}
	free(buffer);
	return (bigstr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*bigstr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	bigstr = ft_chunk_of_fd(fd, bigstr);
	if (!bigstr)
		return (NULL);
	line = ft_perfect_line(bigstr);
	bigstr = ft_new_line(bigstr);
	return (line);
}
