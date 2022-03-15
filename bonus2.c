/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:40:26 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/28 18:10:03 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_monster(t_data *data, t_img *img, t_map *map)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img->monster_up, (map->x * IMG_WIDTH), (map->y * IMG_HEIGHT));
}

void	ft_enemy_utils1(t_data *data, t_map *map, t_monst *current)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->background, (current->monster_x * IMG_WIDTH),
		(current->monster_y * IMG_HEIGHT));
	map->map[current->monster_y][current->monster_x] = '0';
	current->monster_x -= 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->monster_left, (current->monster_x * IMG_WIDTH),
		(current->monster_y * IMG_HEIGHT));
	map->map[current->monster_y][current->monster_x] = 'M';
	if (current->monster_x == data->hero_x
		&& (current->monster_y == data->hero_y))
		ft_gameover(data);
}

void	ft_enemy_utils2(t_data *data, t_map *map, t_monst *current)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->background, (current->monster_x * IMG_WIDTH),
		(current->monster_y * IMG_HEIGHT));
	map->map[current->monster_y][current->monster_x] = '0';
	current->monster_x += 1;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->monster_right, (current->monster_x * IMG_WIDTH),
		(current->monster_y * IMG_HEIGHT));
	map->map[current->monster_y][current->monster_x] = 'M';
	if (current->monster_x == data->hero_x
		&& (current->monster_y == data->hero_y))
		ft_gameover(data);
	current->way = 1;
}

void	ft_ennemy(t_data *data, t_map *map, t_monst *current)
{
	if (current->m == 9000 / data->nbmonst)
	{
		if (map->map[current->monster_y][current->monster_x - 1] != '1'
		&& current->way == 0
		&& map->map[current->monster_y][current->monster_x - 1] != 'M'
		&& (map->map[current->monster_y][current->monster_x - 1] != 'C')
		&& (map->map[current->monster_y][current->monster_x - 1] != 'E'))
			ft_enemy_utils1(data, map, current);
		else if (map->map[current->monster_y][current->monster_x + 1] != '1'
		&& (map->map[current->monster_y][current->monster_x + 1] != 'M')
		&& (map->map[current->monster_y][current->monster_x + 1] != 'C')
		&& (map->map[current->monster_y][current->monster_x + 1] != 'E'))
			ft_enemy_utils2(data, map, current);
		else if (current->way == 1)
		{
			current->m = 8999 / data->nbmonst;
			current->way = 0;
		}
		else
			current->way = 0;
	}
	if (current->m == 9000 / data->nbmonst)
		current->m = 0;
	current->m++;
}
