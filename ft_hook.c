/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:02:18 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/28 18:10:48 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_hook(int key, t_data *data)
{
	if (key == 53)
		ft_exit(data);
	if (key == 13 || key == 0 || key == 1 || key == 2)
	{
		if (key == 13)
			data->dir = U;
		else if (key == 1)
			data->dir = D;
		else if (key == 0)
			data->dir = L;
		else if (key == 2)
			data->dir = R;
		ft_move(data);
	}
	if (data->map->map[data->hero_y][data->hero_x] == 'E')
		ft_win(data);
	return (0);
}

void	ft_win(t_data *data)
{
	printf("Congratulations , you won !!!\n");
	printf("You are now the richest adventurer , invest in dogecoin :D\n");
	ft_exit(data);
}

void	ft_gameover(t_data *data)
{
	printf("You are dead , no big surprise\n");
	printf("Try again !\n");
	ft_exit(data);
}

void	ft_collect(t_data *data, t_img *img, t_map *map)
{
	map->map[data->hero_y][data->hero_x] = '0';
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->background,
		(data->hero_x * IMG_WIDTH), (data->hero_y * IMG_HEIGHT));
	data->nbcollect++;
	ft_hero_move(data, map, img);
}
