/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:10:59 by asaffroy          #+#    #+#             */
/*   Updated: 2022/02/04 10:22:20 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map3(int t, t_map *map)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	map->fd = open(map->map_name, O_RDONLY);
	map->line = get_next_line(map->fd);
	a = ft_strlen(map->line);
	free(map->line);
	while (t - 1 > 0)
	{
		map->line = get_next_line(map->fd);
		b = ft_strlen(map->line);
		if ((b != a && (t - 2 != 0))
			|| (t - 2 == 0 && map->line[a - 1] != '\0'))
		{
			printf("ERROR\nmap is not a rectangle.KO\n");
			free(map->line);
			return (0);
		}
		free(map->line);
		t--;
	}
	close(map->fd);
	return (1);
}

int	check_map4(int i, int t, t_map *map, t_data *data)
{
	int	s[3];

	s[0] = 0;
	s[1] = 0;
	s[2] = 0;
	map->fd = open(map->map_name, O_RDONLY);
	while (t > 0)
	{
		i = -1;
		map->line = get_next_line(map->fd);
		while (map->line[++i])
		{
			if (map->line[i] == 'C')
				s[0]++;
			else if (map->line[i] == 'P')
				s[1]++;
			else if (map->line[i] == 'E')
				s[2]++;
		}
		free(map->line);
		t--;
	}
	data->nbcollectible = s[0];
	close(map->fd);
	return (check_map4_util(s[0], s[1], s[2]));
}

int	check_map4_util(int c, int p, int e)
{
	int	a;

	a = 1;
	if (c < 1)
	{
		printf("ERROR\nyou must have at least one collectible in your map\n");
		a = 0;
	}
	if (p < 1 || p > 1)
	{
		if (p < 1)
			printf
			("ERROR\nyou must have at least one starting position in your map\n");
		a = 0;
	}
	if (e < 1)
	{
		printf("ERROR\nyou must have at least one exit in your map\n");
		a = 0;
	}
	if (p > 1)
		printf("ERROR\ntoo much starting position in your map\n");
	if (a == 1)
		printf("minimun number of exit, collectible and starting position.OK\n");
	return (a);
}
