/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:13:13 by asaffroy          #+#    #+#             */
/*   Updated: 2021/11/30 13:17:47 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_in(char *str, char *charset)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (str[i])
	{
		check = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				check = 1;
			else if (str[i] != charset[j] && check != 1)
				check = 0;
			j++;
		}
		if (check == 0)
			return (0);
		j = 0;
		i++;
	}
	return (check);
}

int	ft_line_length(int fd)
{
	char	buffer[1];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}
