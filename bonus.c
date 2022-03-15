/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:10:33 by asaffroy          #+#    #+#             */
/*   Updated: 2022/02/04 09:22:32 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_animation_d(t_data *data)
{
	static int	i = 0;

	if (data->dir == D)
	{
		if (i == 8000)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->hero_up, (data->hero_x * IMG_WIDTH),
				(data->hero_y * IMG_HEIGHT));
		}
		if (i == 8000 * 2)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->hero_up2, (data->hero_x * IMG_WIDTH),
				(data->hero_y * IMG_HEIGHT));
			i = 0;
		}
	}
	i++;
	return (0);
}

int	ft_animation_u(t_data *data)
{
	static int	j = 0;

	if (j == 8000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->hero_down, (data->hero_x * IMG_WIDTH),
			(data->hero_y * IMG_HEIGHT));
	}
	if (j == 8000 * 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->hero_down2, (data->hero_x * IMG_WIDTH),
			(data->hero_y * IMG_HEIGHT));
	j = 0;
	}
	j++;
	return (0);
}

int	ft_animation_r(t_data *data)
{
	static int	k = 0;

	if (k == 8000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->hero_right, (data->hero_x * IMG_WIDTH),
			(data->hero_y * IMG_HEIGHT));
	}
	if (k == 8000 * 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->hero_right2, (data->hero_x * IMG_WIDTH),
			(data->hero_y * IMG_HEIGHT));
		k = 0;
	}
	k++;
	return (0);
}

int	ft_animation_l(t_data *data)
{
	static int	l = 0;

	if (l == 8000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->hero_left2, (data->hero_x * IMG_WIDTH),
			(data->hero_y * IMG_HEIGHT));
	}
	if (l == 8000 * 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->hero_left, (data->hero_x * IMG_WIDTH),
			(data->hero_y * IMG_HEIGHT));
		l = 0;
	}
	l++;
	return (0);
}

int	ft_bonus(t_data *data)
{
	if (data->dir == D)
		ft_animation_d(data);
	else if (data->dir == U)
		ft_animation_u(data);
	else if (data->dir == R)
		ft_animation_r(data);
	else if (data->dir == L)
		ft_animation_l(data);
	if (data->nbmonst > 0)
	{
		ft_ennemy(data, data->map, data->monst);
		if (data->monst->next == NULL)
			data->monst = data->top;
		else
			data->monst = data->monst->next;
	}
	return (0);
}
