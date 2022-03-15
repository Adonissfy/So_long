/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:15:00 by asaffroy          #+#    #+#             */
/*   Updated: 2022/02/04 09:48:17 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_frame(t_data *data, t_img *img, t_map *map)
{
	int	i;

	i = 0;
	put_background(data, img);
	create_map(data, map, img);
	if (i == 0)
	{
		printf("\n\nPress either w,a,s,d to start\n\n");
		i++;
	}
	mlx_hook(data->win_ptr, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win_ptr, ft_hook, data);
	return (0);
}

int	ft_exit(t_data *data)
{
	t_monst	*temp;

	img_destroy(data, data->img);
	free(data->map->map);
	if (data->monst)
	{
		while (data->monst->next)
		{
			temp = data->monst;
			data->monst = data->monst->next;
			free(temp);
		}
		if (data->monst)
			free(data->monst);
	}
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("BYE BYE\n");
	exit(EXIT_SUCCESS);
}

int	main_util(t_data *data, t_map *map, char **argv)
{
	int	i;

	i = 0;
	if (testparse(data, map, argv, i))
	{
		data->check = 0;
		ft_settab(map);
		ft_fillmonst(data);
		data->mlx_ptr = mlx_init();
		if (!data->mlx_ptr)
		{
			printf("Error\nprogramm init failed\n");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

int	testparse(t_data *data, t_map *map, char **argv, int i)
{
	int		t;

	map->map_name = argv[1];
	window_size(data, map);
	i = ft_count_line(map);
	t = i;
	if (!ft_check_map1(i, map))
		exit(EXIT_FAILURE);
	if (!check_map2(i, t, map))
	{
		printf("ERROR\nmap not surrounded by walls.KO\n");
		exit(EXIT_FAILURE);
	}
	printf ("map surrounded by walls.OK\n");
	if (!check_map3(t, map))
		exit(EXIT_FAILURE);
	printf("map is a rectangle.OK\n");
	if (!check_map4(i, t, map, data))
		exit(EXIT_FAILURE);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_data	data;
	t_img	img;
	t_monst	monst;

	data.map = &map;
	data.img = &img;
	data.monst = &monst;
	if (argc != 2)
		printf("nombre incorrect d'arguments\n");
	else
	{
		main_util(&data, &map, argv);
		init_map(&img, &data);
		data.win_ptr = mlx_new_window(data.mlx_ptr, data.size_x,
				data.size_y, "./so_long");
		put_frame(&data, &img, &map);
		mlx_loop_hook(data.mlx_ptr, ft_bonus, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
