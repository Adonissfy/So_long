/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:49:12 by asaffroy          #+#    #+#             */
/*   Updated: 2021/11/09 09:41:58 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mallocitoa(int compt, int neg, char **str, int n)
{
	while (!(n >= 0 && n <= 9))
	{
		n /= 10;
		compt++;
	}
	compt += neg;
	*str = malloc(sizeof(char) * (compt + 1));
	if (!*str)
		return (-1);
	return (compt);
}

static char	*ft_filltabitoa(int compt, char *str, int n)
{
	str[compt] = '\0';
	compt--;
	while (n > 9)
	{
		str[compt--] = (n % 10) + 48;
		n /= 10;
	}
	str[compt] = (n % 10) + 48;
	if (compt == 1)
		str[--compt] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		neg;
	char	*str;
	int		compt;

	neg = 0;
	compt = 1;
	if (n == -2147483648)
	{
		str = malloc(sizeof(char) * 12);
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		return (ft_filltabitoa(11, str, n));
	}
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	compt = ft_mallocitoa(compt, neg, &str, n);
	if (compt == -1)
		return (NULL);
	return (ft_filltabitoa(compt, str, n));
}
