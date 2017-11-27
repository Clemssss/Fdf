# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/24 16:33:19 by clegirar          #+#    #+#              #
#    Updated: 2017/11/27 12:10:55 by clegirar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

SRCS	=	./srcs/main.c								\
				./srcs/loop_img.c						\
				./srcs/del_struct.c					\
				./srcs/change_tab.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-I./includes/ -I./libft/ -I./minilibx_macos/ -g3

all			:	$(NAME)

$(NAME)	:	$(OBJS)
					make -C libft
					make -C minilibx_macos
					$(CC) $(OBJS) -L libft -lft -lmlx -framework OpenGL -framework AppKit -framework Opencl -lm -o $(NAME)

clean		:
					make clean -C libft
					make clean -C minilibx_macos
					rm -rf $(OBJS)

%.o			:	%.c
					$(CC) -o $@ -c $< $(CFLAGS)

fclean	:
					make fclean -C libft
					make clean -C minilibx_macos
					rm -rf $(OBJS) $(NAME)

re			:	fclean all

.PHONY	:	all clean fclean re
