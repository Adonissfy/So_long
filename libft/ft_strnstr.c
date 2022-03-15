/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:59:07 by asaffroy          #+#    #+#             */
/*   Updated: 2021/11/05 13:31:55 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	l;

	if (*needle == 0)
		return ((char *)haystack);
	n = (char *)needle;
	while (*haystack && len > 0)
	{
		h = (char *)haystack;
		l = len;
		while (*haystack && *needle && *haystack == *needle && len-- > 0)
		{
			haystack++;
			needle++;
		}
		if (!*needle)
			return (h);
		haystack = ++h;
		needle = n;
		len = --l;
	}
	return (NULL);
}
