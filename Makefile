# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/24 16:33:19 by clegirar          #+#    #+#              #
#    Updated: 2017/11/30 12:24:15 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

SRCS	=	./srcs/main.c								\
				./srcs/loop_img.c						\
				./srcs/del_struct.c					\
				./srcs/ft_strsplit_int.c		\
				./srcs/pos.c								\
				./srcs/put_pxl.c						\
				./srcs/events.c							\
				./srcs/do_change.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I./includes/ -I./libft/ -I./minilibx_macos/ -I./lib_mlx/includes/

all			:	$(NAME)

$(NAME)	:	$(OBJS)
					make -C libft
					make -C minilibx_macos
					make -C lib_mlx
					$(CC) $(OBJS) lib_mlx/ft_libmlx.a -L libft -lft -lmlx -framework OpenGL -framework AppKit -framework Opencl -lm -o $(NAME)

clean		:
					make clean -C libft
					make clean -C minilibx_macos
					make clean -C lib_mlx
					rm -rf $(OBJS)

%.o			:	%.c
					$(CC) -o $@ -c $< $(CFLAGS)

fclean	:
					make fclean -C libft
					make clean -C minilibx_macos
					make fclean -C lib_mlx
					rm -rf $(OBJS) $(NAME)

re			:	fclean all

.PHONY	:	all clean fclean re
