/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:58:56 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/29 09:02:53 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hero_move(t_data *data, t_map *map, t_img *img)
{
	ft_print_moov(data, img, data->movcount, ft_int_len(data->movcount));
	if (map->map[data->hero_y][data->hero_x] == 'M')
		ft_gameover(data);
	else if (data->dir == U)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->hero_down,
			(data->hero_x * IMG_WIDTH), (data->hero_y * IMG_HEIGHT));
	else if (data->dir == D)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->hero_up,
			(data->hero_x * IMG_WIDTH), (data->hero_y * IMG_HEIGHT));
	else if (data->dir == R)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->hero_right,
			(data->hero_x * IMG_WIDTH), (data->hero_y * IMG_HEIGHT));
	else if (data->dir == L)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->hero_left,
			(data->hero_x * IMG_WIDTH), (data->hero_y * IMG_HEIGHT));
}

void	ft_settab(t_map *map)
{
	char	buff[101];
	char	*temp;
	int		i;

	i = 1;
	temp = NULL;
	map->fd = open(map->map_name, O_RDONLY);
	while (i > 0)
	{
		i = read(map->fd, buff, 100);
		if (i == -1)
		{
			printf("ERROR\nread of map failed\n");
			exit(EXIT_FAILURE);
		}
		buff[i] = '\0';
		temp = ft_strjoincustom(temp, buff);
		if (!temp)
		{
			printf("ERROR\nmalloc of map failed\n");
			exit(EXIT_FAILURE);
		}
	}
	map->map = ft_split(temp, '\n');
	free(temp);
}

void	ft_move(t_data *data)
{
	data->movcount++;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->background, (data->hero_x * IMG_WIDTH),
		(data->hero_y * IMG_HEIGHT));
	if (data->dir == U && data->map->map[data->hero_y - 1][data->hero_x] != '1'
		&& (data->map->map[data->hero_y - 1][data->hero_x] != 'E'
		|| data->nbcollectible == data->nbcollect))
		data->hero_y -= 1;
	else if ((data->map->map[data->hero_y - 1][data->hero_x] == 'E'
		|| data->map->map[data->hero_y - 1][data->hero_x] == '1')
		&& data->dir == U)
	{
		if (data->map->map[data->hero_y - 1][data->hero_x] == 'E')
			printf("You have to collect all the coins first\n\n");
		data->movcount--;
	}
	ft_move2(data, data->map, data->img);
}

void	ft_move2(t_data *data, t_map *map, t_img *img)
{
	if (data->dir == D
		&& data->map->map[data->hero_y + 1][data->hero_x] != '1'
		&& (data->map->map[data->hero_y + 1][data->hero_x] != 'E'
		|| data->nbcollectible == data->nbcollect))
		data->hero_y += 1;
	else if ((map->map[data->hero_y + 1][data->hero_x] == 'E'
		|| map->map[data->hero_y + 1][data->hero_x] == '1') && data->dir == D)
	{
		if (map->map[data->hero_y + 1][data->hero_x] == 'E')
			printf("You have to collect all the coins first\n\n");
		data->movcount--;
	}
	if (data->dir == R
		&& map->map[data->hero_y][data->hero_x + 1] != '1'
		&& (map->map[data->hero_y][data->hero_x + 1] != 'E'
		|| data->nbcollectible == data->nbcollect))
		data->hero_x += 1;
	else if ((map->map[data->hero_y][data->hero_x + 1] == 'E'
		|| map->map[data->hero_y][data->hero_x + 1] == '1') && data->dir == R)
	{
		if (map->map[data->hero_y][data->hero_x + 1] == 'E')
			printf("You have to collect all the coins first\n\n");
		data->movcount--;
	}
	ft_move3(data, map, img);
}

void	ft_move3(t_data *data, t_map *map, t_img *img)
{
	if (data->dir == L
		&& map->map[data->hero_y][data->hero_x - 1] != '1'
		&& (map->map[data->hero_y][data->hero_x - 1] != 'E'
		|| data->nbcollectible == data->nbcollect))
		data->hero_x -= 1;
	else if ((map->map[data->hero_y][data->hero_x - 1] == 'E'
		|| map->map[data->hero_y][data->hero_x - 1] == '1') && data->dir == L)
	{
		if (map->map[data->hero_y][data->hero_x - 1] == 'E')
			printf("You have to collect all the coins first\n\n");
		data->movcount--;
	}
	ft_hero_move(data, map, img);
	if (map->map[data->hero_y][data->hero_x] == 'C')
		ft_collect(data, img, map);
}
