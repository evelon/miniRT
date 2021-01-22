# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolim <jolim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 07:07:34 by jolim             #+#    #+#              #
#    Updated: 2021/01/03 21:30:51 by jolim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re bonus

AR = ar
ARFLAGS = rcs

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = ../libget_next_line.a

OBJS = get_next_line.o \
		get_next_line_utils.o \

SRCS = $(OBJS:.o=.c)
INCS = get_next_line.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o : %.c $(INCS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
