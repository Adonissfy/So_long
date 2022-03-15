# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 14:33:49 by asaffroy          #+#    #+#              #
#    Updated: 2021/12/28 18:29:21 by asaffroy         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS        = check_map.c\
			check_map2.c\
			ft_hook.c\
			move.c\
			init_map.c\
			init_monst.c\
			load_map.c\
			so_long_utils.c\
			so_long.c\
			bonus.c\
			bonus2.c\
			bonus3.c\
			  gnl/get_next_line.c gnl/get_next_line_utils.c
NAME		= so_long
minilibx	= mlx/libmlx.a
libft		= libft/libft.a
OBJS_DIR	= objs/
OBJS		= $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx -L./mlx

$(OBJS_DIR)%.o : %.c so_long.h
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)gnl
	$(CC) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED) compile
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) libft/libft.a

all: $(NAME)

bonus: $(NAME)

compile:
	@$(MAKE) -C mlx
	@echo " [ OK ] | Minilibx ready!"
	@$(MAKE) -C libft
	@echo " [ OK ] | Libft ready!"

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) clean -C libft
	@echo "object files removed"

fclean: clean
	@$(MAKE) clean -C mlx
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)
	@echo "fclean : done"

re: fclean all

.PHONY:        all clean fclean re compile bonus