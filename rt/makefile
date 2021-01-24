# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolim <jolim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 14:55:13 by jolim             #+#    #+#              #
#    Updated: 2021/01/24 16:33:13 by jolim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all re test

CC = gcc
AR = ar
ARFLAGS = rcsv

CFLAGS = -Wall -Werror -Wextra
SAN = -g3 -fsanitize=address

NAME = ../librt.a

SOURCES = main.c \
		temp.c \
		color.c \
		img_to_bmp.c \
		vector_0.c \
		vector_1.c \
		vector_2.c \
		parse_element.c \
		parse_manage_lst.c \
		parse_object_0.c \
		parse_object_1.c \
		parse_scene.c \
		parse_utils_0.c \
		parse_utils_1.c \
		parse_utils_2.c \
		scene_paint.c \
		rt_obj.c \
		rt_obj_t.c \
		rt_obj_0.c \
		rt_obj_1.c \
		rt_iter.c \
		rt_lighting.c \
		rt_utils.c
OBJECTS = $(SOURCES:.c=.o)

SRCS = $(addprefix srcs/,$(SOURCES))
OBJS = $(addprefix objects/,$(OBJECTS))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

objects/%o : srcs/%c
	$(CC) $(CFLAGS) $(SAN) -o $@ -c $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all