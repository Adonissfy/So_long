/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:36:07 by asaffroy          #+#    #+#             */
/*   Updated: 2021/11/04 11:45:41 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int c, size_t n)
{
	size_t			i;
	unsigned char	*b;

	b = (unsigned char *)a;
	i = 0;
	while (i < n)
		b[i++] = (unsigned char)c;
	return (b);
}
