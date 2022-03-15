/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:49:16 by asaffroy          #+#    #+#             */
/*   Updated: 2022/02/04 09:21:12 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_monst	*new_enemy(int x, int y)
{
	t_monst	*monst;

	monst = malloc(sizeof(t_monst));
	if (monst == NULL)
	{
		printf("ERROR\nmalloc of struct ennemy failed\n");
		exit(EXIT_FAILURE);
	}
	monst->monster_x = x;
	monst->monster_y = y;
	monst->way = 0;
	monst->m = 0;
	monst->next = NULL;
	return (monst);
}

t_monst	*last_enemy(t_monst *list)
{
	if (!list)
		return (list);
	while (list->next)
		list = list->next;
	return (list);
}

void	add_enemy(t_data *data, int x, int y)
{
	static int		a = 0;
	t_monst			*new;

	new = new_enemy(x, y);
	if (new == NULL)
		return ;
	if (a == 0)
	{
		data->monst = new;
		a++;
	}
	else
		last_enemy(data->monst)->next = new;
}

void	ft_fillmonst(t_data *data)
{
	static int	x = 1;
	static int	y = 1;

	data->monst = NULL;
	while (data->map->map[y][x])
	{
		if (data->map->map[y][x] == 'M')
		{
			add_enemy(data, x, y);
			data->nbmonst++;
		}
		if (x == (data->size_x / IMG_WIDTH - 1)
			&& y < (data->size_y / IMG_HEIGHT - 1))
		{
			x = 1;
			y++;
		}
		else
			x++;
	}
	data->top = data->monst;
}
