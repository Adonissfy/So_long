/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:35:25 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/13 11:52:30 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_int_len(int x)
{
	int	y;

	y = 0;
	if (x > 0)
	{
		if (x > 9)
			y += ft_int_len(x / 10);
		y++;
	}
	return (y);
}

void	ft_print_moov(t_data *data, t_img *img, int x, int y)
{
	if (x > 9)
		ft_print_moov(data, img, x / 10, y - 1);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img->nmb[x % 10], 16 + y * 16, 0);
}

void	img_destroy(t_data *data, t_img *img)
{
	if (img != 0)
	{
		if (img->background != 0)
			mlx_destroy_image(data->mlx_ptr, img->background);
		if (img->wall != 0)
			mlx_destroy_image(data->mlx_ptr, img->wall);
		if (img->collectible != 0)
			mlx_destroy_image(data->mlx_ptr, img->collectible);
		if (img->exit != 0)
			mlx_destroy_image(data->mlx_ptr, img->exit);
		if (img->hero_up != 0)
			mlx_destroy_image(data->mlx_ptr, img->hero_up);
		if (img->hero_down != 0)
			mlx_destroy_image(data->mlx_ptr, img->hero_down);
		if (img->hero_right != 0)
			mlx_destroy_image(data->mlx_ptr, img->hero_right);
		if (img->hero_left != 0)
			mlx_destroy_image(data->mlx_ptr, img->hero_left);
		if (img->hero_up2 != 0)
			mlx_destroy_image(data->mlx_ptr, img->hero_up2);
		if (img->hero_down2 != 0)
			mlx_destroy_image(data->mlx_ptr, img->hero_down2);
	}
	img_destroy2(data, img);
}

void	img_destroy2(t_data *data, t_img *img)
{
	int	i;

	i = -1;
	if (img->hero_right2 != 0)
		mlx_destroy_image(data->mlx_ptr, img->hero_right2);
	if (img->hero_left2 != 0)
		mlx_destroy_image(data->mlx_ptr, img->hero_left2);
	if (img->monster_right != 0)
		mlx_destroy_image(data->mlx_ptr, img->monster_right);
	if (img->monster_left != 0)
		mlx_destroy_image(data->mlx_ptr, img->monster_left);
	if (img->monster_up != 0)
		mlx_destroy_image(data->mlx_ptr, img->monster_up);
	while (++i < 10)
		mlx_destroy_image(data->mlx_ptr, img->nmb[i]);
	i = 0;
	while (data->map->map[i])
	{
		free(data->map->map[i]);
		i++;
	}
}
