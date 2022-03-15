/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:01:23 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/09 19:09:36 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define IMG_WIDTH 32
# define IMG_HEIGHT 32
# define U 8
# define D 4
# define R 5
# define L 6

typedef struct s_map
{
	char	*line;
	int		fd;
	int		x;
	int		y;
	char	*map_name;
	char	**map;
}	t_map;

typedef struct s_img
{
	void	*hero_up;
	void	*hero_left;
	void	*hero_right;
	void	*hero_down;
	void	*hero_up2;
	void	*hero_down2;
	void	*hero_right2;
	void	*hero_left2;
	void	*monster_up;
	void	*monster_left;
	void	*monster_right;
	void	*background;
	void	*collectible;
	void	*exit;
	void	*wall;
	void	*nmb[10];
}	t_img;

typedef struct s_monst
{
	int				monster_x;
	int				monster_y;
	int				way;
	int				m;
	struct s_monst	*next;
}	t_monst;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				size_x;
	int				size_y;
	int				movcount;
	int				nbcollect;
	int				hero_x;
	int				hero_y;
	int				nbcollectible;
	int				nbmonst;
	int				dir;
	int				check;
	t_img			*img;
	t_map			*map;
	t_monst			*monst;
	struct s_monst	*top;
}	t_data;

int		ft_check_in(char *str, char *charset);
int		ft_count_line(t_map *map);
int		ft_check_map1(int i, t_map *map);
int		check_map2(int i, int t, t_map *map);
int		check_map2_util(t_map *map, int a, int check);
int		check_map3(int t, t_map *map);
int		check_map4(int i, int t, t_map *map, t_data *data);
int		check_map4_util(int c, int p, int e);
void	window_size(t_data *data, t_map *map);
int		ft_line_length(int fd);
void	init_map(t_img *img, t_data *data);
void	init_map2(t_img *img, t_data *data);
void	init_map3(t_img *img, t_data *data);
void	init_map4(t_img *img, t_data *data);
int		testparse(t_data *data, t_map *map, char **argv, int i);
int		put_frame(t_data *data, t_img *img, t_map *map);
int		ft_exit(t_data *data);
void	put_background(t_data *data, t_img *img);
void	create_map(t_data *data, t_map *map, t_img *img);
void	ft_put_obj(t_data *data, t_img *img, t_map *map, char *obj_name);
void	ft_put_player(t_data *data, t_img *img, t_map *map);
int		ft_hook(int key, t_data *t_data);
void	ft_settab(t_map *map);
void	ft_move(t_data *data);
void	ft_move2(t_data *data, t_map *map, t_img *img);
void	ft_move3(t_data *data, t_map *map, t_img *img);
void	ft_collect(t_data *data, t_img *img, t_map *map);
void	ft_win(t_data *data);
void	ft_gameover(t_data *data);
int		ft_bonus(t_data *data);
void	ft_put_monster(t_data *data, t_img *img, t_map *map);
void	ft_ennemy(t_data *data, t_map *map, t_monst *current);
void	ft_fillmonst(t_data *data);
t_monst	*last_enemy(t_monst *list);
void	ft_inittop(t_data *data);
void	ft_enemy_utils1(t_data *data, t_map *map, t_monst *current);
void	ft_enemy_utils2(t_data *data, t_map *map, t_monst *current);
int		ft_int_len(int x);
void	ft_print_moov(t_data *data, t_img *img, int x, int y);
void	img_destroy(t_data *data, t_img *img);
void	img_destroy2(t_data *data, t_img *img);
void	ft_hero_move(t_data *data, t_map *map, t_img *img);

#endif