/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:42:35 by asaffroy          #+#    #+#             */
/*   Updated: 2021/11/09 11:44:31 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	b;

	b = 0;
	if (!s)
		return ;
	while (s[b] != '\0')
	{
		write(fd, &s[b], 1);
		b++;
	}
	write(fd, "\n", 1);
}
