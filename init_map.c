/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:49:34 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/08 17:48:42 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_img *img, t_data *data)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./sprites/hero_up.xpm";
	img->hero_up = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	path = "./sprites/hero_down.xpm";
	img->hero_down = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	path = "./sprites/hero_right.xpm";
	img->hero_right = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	path = "./sprites/hero_left.xpm";
	img->hero_left = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	path = "./sprites/background.xpm";
	img->background = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	path = "./sprites/collectible.xpm";
	img->collectible = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	init_map2(img, data);
}

void	init_map2(t_img *img, t_data *data)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./sprites/exit.xpm";
	img->exit = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	path = "./sprites/wall.xpm";
	img->wall = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	path = "./sprites/hero_up2.xpm";
	img->hero_up2 = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	path = "./sprites/hero_down2.xpm";
	img->hero_down2 = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	path = "./sprites/hero_left2.xpm";
	img->hero_left2 = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	path = "./sprites/hero_right2.xpm";
	img->hero_right2 = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	init_map3(img, data);
	data->nbcollect = 0;
	data->movcount = 0;
}

void	init_map3(t_img *img, t_data *data)
{
	char	*path;
	int		img_width;
	int		img_height;

	path = "./sprites/monster_up.xpm";
	img->monster_up = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	path = "./sprites/monster_left.xpm";
	img->monster_left = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	path = "./sprites/monster_right.xpm";
	img->monster_right = mlx_xpm_file_to_image(data->mlx_ptr, path, &img_width,
			&img_height);
	init_map4(img, data);
}

void	init_map4(t_img *img, t_data *data)
{
	int		img_width;
	int		img_height;

	img->nmb[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/0.xpm",
			&img_width, &img_height);
	img->nmb[1] = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/1.xpm",
			&img_width, &img_height);
	img->nmb[2] = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/2.xpm",
			&img_width, &img_height);
	img->nmb[3] = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/3.xpm",
			&img_width, &img_height);
	img->nmb[4] = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/4.xpm",
			&img_width, &img_height);
	img->nmb[5] = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/5.xpm",
			&img_width, &img_height);
	img->nmb[6] = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/6.xpm",
			&img_width, &img_height);
	img->nmb[7] = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/7.xpm",
			&img_width, &img_height);
	img->nmb[8] = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/8.xpm",
			&img_width, &img_height);
	img->nmb[9] = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/9.xpm",
			&img_width, &img_height);
}
