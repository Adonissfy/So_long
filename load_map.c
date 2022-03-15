/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:31:14 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/07 19:34:19 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_size(t_data *data, t_map *map)
{
	int		fd;

	fd = open(map->map_name, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nmap_path is invalid\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(map->map_name, ".ber", ft_strlen(map->map_name)) == NULL)
	{
		printf("Error\nmap is not a .ber\n");
		exit(EXIT_FAILURE);
	}
	data->size_x = (ft_line_length(fd) * IMG_WIDTH);
	data->size_y = (ft_count_line(map) * IMG_HEIGHT);
}

void	put_background(t_data *data, t_img *img)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				img->background, x, y);
			x += IMG_WIDTH;
		}
		y += IMG_HEIGHT;
	}
}

void	create_map(t_data *data, t_map *map, t_img *img)
{
	map->x = 0;
	map->y = 0;
	map->fd = open(map->map_name, O_RDONLY);
	map->line = get_next_line(map->fd);
	while (map->y < (data->size_y / IMG_HEIGHT))
	{
		if (map->line[map->x] == 'P')
			ft_put_player(data, img, map);
		else if (map->line[map->x] == '1')
			ft_put_obj(data, img, map, "img->wall");
		else if (map->line[map->x] == 'C' || map->line[map->x] == 'M')
			ft_put_obj(data, img, map, "img->collectible");
		else if (map->line[map->x] == 'E')
			ft_put_obj(data, img, map, "img->exit");
		if (map->x < (data->size_x / IMG_WIDTH))
			map->x += 1;
		else
		{
			map->y += 1;
			map->x = 0;
			free(map->line);
			map->line = get_next_line(map->fd);
		}
	}
	free(map->line);
}

void	ft_put_obj(t_data *data, t_img *img, t_map *map, char *obj_name)
{
	if (!ft_strncmp(obj_name, "img->exit", 9))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->exit,
			(map->x * IMG_WIDTH), (map->y * IMG_HEIGHT));
	}
	else if (!ft_strncmp(obj_name, "img->wall", 9))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->wall,
			(map->x * IMG_WIDTH), (map->y * IMG_HEIGHT));
	}
	if (!ft_strncmp(obj_name, "img->collectible", 16))
	{
		if (map->line[map->x] == 'M')
			ft_put_monster(data, img, map);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				img->collectible, (map->x * IMG_WIDTH), (map->y * IMG_HEIGHT));
	}
}

void	ft_put_player(t_data *data, t_img *img, t_map *map)
{
	data->hero_x = map->x;
	data->hero_y = map->y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->hero_up,
		(data->hero_x * IMG_WIDTH), (data->hero_y * IMG_HEIGHT));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img->nmb[0], 32, 0);
}
