/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:36:25 by asaffroy          #+#    #+#             */
/*   Updated: 2021/11/17 10:43:52 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	int		i;
	char	*str;

	i = 0;
	str = " \t\n\v\f\r";
	while (i < 6)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_sign(char c)
{
	if (c == 45)
		return (1);
	return (0);
}

static int	ft_testlong(int sign)
{
	if (sign == 1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int			a;
	int			sign;
	long int	j;

	a = 0;
	sign = 0;
	j = 0;
	while (ft_isspace(str[a]) == 1)
		a++;
	if ((str[a] == 45 || str[a] == 43) && str[a + 1] >= 48 && str[a + 1] <= 58)
	{
		sign = ft_sign(str[a]);
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		j = j * 10 + (str[a] - 48);
		a++;
		if (j > 2147483648)
			return (ft_testlong(sign));
	}
	if (sign == 1 && j > 0)
		j *= -1;
	return (j);
}
