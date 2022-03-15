/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:45:51 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/03 16:50:33 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_line(t_map *map)
{
	int	i;
	int	a;

	i = 0;
	a = 1;
	map->fd = open(map->map_name, O_RDONLY);
	while (a)
	{
		map->line = get_next_line(map->fd);
		if (!map->line)
			a = 0;
		else
			i++;
		free(map->line);
	}
	close(map->fd);
	return (i);
}

int	ft_check_map1(int i, t_map *map)
{
	int	a;
	int	check;

	a = 1;
	check = 0;
	map->fd = open(map->map_name, O_RDONLY);
	while (i-- > 0)
	{
		map->line = get_next_line(map->fd);
		if (ft_check_in(map->line, "CPE01M\n") == 0)
		{
			printf("ERROR\nchar in line %d.KO\n", a);
			return (0);
		}
		else
		{
			printf("char in line %d.OK\n", a);
			check = 1;
		}
		a++;
		free (map->line);
	}
	close(map->fd);
	return (check);
}

int	check_map2(int i, int t, t_map *map)
{
	int	a;
	int	check;

	map->fd = open(map->map_name, O_RDONLY);
	check = 1;
	while (t > 0)
	{
		a = 0;
		map->line = get_next_line(map->fd);
		if (t == i || t == 1)
		{
			while (map->line[a])
			{
				if (map->line[a] != '1' && (map->line[a] != '\n'))
					check = 0;
				a++;
			}
		}
		else
			check = check_map2_util(map, a, check);
		t--;
		free(map->line);
	}
	close(map->fd);
	return (check);
}

int	check_map2_util(t_map *map, int a, int check)
{
	while (map->line[a])
		a++;
	if (map->line[0] != '1' || map->line[a - 2] != '1')
		check = 0;
	return (check);
}
