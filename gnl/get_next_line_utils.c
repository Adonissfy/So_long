/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:47:08 by asaffroy          #+#    #+#             */
/*   Updated: 2021/11/17 13:59:16 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenmod(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchrmod(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlenmod(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoincustom(char *bigstr, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!bigstr)
	{
		bigstr = (char *)malloc(sizeof(char) * 1);
		bigstr[0] = '\0';
	}
	if (!bigstr || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlenmod(bigstr)
					+ ft_strlenmod(buffer)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (bigstr)
		while (bigstr[++i] != '\0')
			str[i] = bigstr[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlenmod(bigstr) + ft_strlenmod(buffer)] = '\0';
	free(bigstr);
	return (str);
}

char	*ft_perfect_line(char *bigstr)
{
	int		i;
	char	*str;

	i = 0;
	if (!bigstr[i])
		return (NULL);
	while (bigstr[i] && bigstr[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (bigstr[i] && bigstr[i] != '\n')
	{
		str[i] = bigstr[i];
		i++;
	}
	if (bigstr[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_line(char *bigstr)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (bigstr[i] && bigstr[i] != '\n')
		i++;
	if (!bigstr[i])
	{
		free(bigstr);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlenmod(bigstr) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (bigstr[i])
		str[j++] = bigstr[i++];
	str[j] = '\0';
	free(bigstr);
	return (str);
}
