# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mypark <mypark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 20:24:15 by mypark            #+#    #+#              #
#    Updated: 2022/05/10 11:01:12 by mypark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minirt
CFLAGS	=	-Wall -Werror -Wextra
VPATH	=	$(shell ls -R)
SRCS_PARSING_UTILS	=	ft_strsep.c\
						parse_double.c\
						parse_vec3.c
SRCS_PARSING		=	parsing.c\
						set_ambient.c\
						set_camera.c\
						add_new_sphere.c\
						add_new_cylinder.c\
						add_new_plane.c\
						add_new_light.c\
						$(SRCS_PARSING_UTILS)
SRCS_VEC3			=	add_vec3.c\
						copy_vec3.c\
						cross_vec3.c\
						div_vec3.c\
						div_vec3_t.c\
						dot_vec3.c\
						dup_vec3.c\
						get_unit_vec3.c\
						get_vec3_len_square.c\
						get_vec3_len.c\
						minus_vec3.c\
						mul_vec3.c\
						mul_vec3_t.c\
						new_vec3.c\
						plus_vec3.c\
						sub_vec3.c
SRCS_MLX_INFO		=	init_mlx_info.c
SRCS_OBJECT			=	new_object.c\
						free_object.c\
						new_plane.c\
						new_sphere.c\
						new_cylinder.c
SRCS_WORLD			=	new_light.c\
						$(SRCS_OBJECT)
SRCS_SCENE			=	init_scene.c\
						clear_scene.c\
						$(SRCS_MLX_INFO)\
						$(SRCS_WORLD)
SRCS_STRUCTURE		=	$(SRCS_PIXEL)\
						$(SRCS_SCENE)\
						$(SRCS_VEC3)
SRCS_UTILS			=	ft_assert.c
SRCS				=	main.c\
						$(SRCS_PARSING)\
						$(SRCS_STRUCTURE)\
						$(SRCS_UTILS)
OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

INCS	=	-I./srcs/parsing/parsing_utils/\
			-I./srcs/parsing/\
			-I./srcs/structure/pixel\
			-I./srcs/structure/pixel/hit_record/\
			-I./srcs/structure/pixel/ray/\
			-I./srcs/structure/scene/\
			-I./srcs/structure/scene/mlx_info/\
			-I./srcs/structure/scene/ambient/\
			-I./srcs/structure/scene/camera/\
			-I./srcs/structure/scene/canvas/\
			-I./srcs/structure/scene/world/\
			-I./srcs/structure/scene/world/light/\
			-I./srcs/structure/scene/world/object/\
			-I./srcs/structure/scene/world/object/cylinder/\
			-I./srcs/structure/scene/world/object/plane/\
			-I./srcs/structure/scene/world/object/sphere/\
			-I./srcs/structure/vec3/\
			-I./srcs/utils/\
			-I./libs/libft/\
			-I./incs

LIBS	=	-L./libs/libft -lft

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LIBS) $^ -o $@

$(LIBS):
	$(MAKE) bonus -C libs/libft

$(OBJ_DIR)/%.o: %.c $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

clean:
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all fclean clean re
