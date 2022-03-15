/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:27:15 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/08 11:56:52 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_malloc(char *str, char c)
{
	int		a;
	int		i;
	int		compt;

	i = 0;
	compt = 0;
	while (str[i])
	{
		a = 0;
		if (str[i] == c)
			a = 1;
		if (a == 0 && i != 0 && str[i - 1] == c)
			compt++;
		if (a == 0 && i == 0)
			compt++;
		i++;
	}
	return (compt);
}

static char	*ft_strdupmod(char *str, char c)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (str[i] && str[i] != c)
		i++;
	if (i < 1)
		return (NULL);
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	while (j < i && str[j] != 0)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}

char	**ft_split(const char *str, char c)
{
	char	**mothertab;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	mothertab = malloc(sizeof(char *) * (ft_malloc((char *)str, c) + 1));
	if (!mothertab)
		return (NULL);
	while (j < ft_malloc((char *)str, c))
	{
		while (str[i] == c)
			i++;
		mothertab[j] = ft_strdupmod((char *)str + i, c);
		j++;
		while ((str[i]) != c && str[i])
			i++;
	}	
	mothertab[j] = 0;
	return (mothertab);
}
