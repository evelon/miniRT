# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolim <jolim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 07:07:34 by jolim             #+#    #+#              #
#    Updated: 2021/01/22 15:03:16 by jolim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

AR = ar
ARFLAGS = rcsv

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = ../liblibft.a

OBJS = ft_isalnum.o \
		ft_isprint.o \
		ft_memcpy.o \
		ft_strdup.o \
		ft_strnstr.o \
		ft_tolower.o \
		ft_atoi.o \
		ft_isalpha.o \
		ft_memccpy.o \
		ft_memmove.o \
		ft_strjoin.o \
		ft_strrchr.o \
		ft_toupper.o \
		ft_bzero.o \
		ft_isascii.o \
		ft_memchr.o \
		ft_memset.o \
		ft_strlen.o \
		ft_strlcat.o \
		ft_strlcpy.o \
		ft_strtrim.o \
		ft_calloc.o \
		ft_isdigit.o \
		ft_memcmp.o \
		ft_strchr.o \
		ft_strncmp.o \
		ft_substr.o \
		ft_split.o \
		ft_itoa.o \
		ft_strmapi.o \
		ft_putchar_fd.o \
		ft_putstr_fd.o \
		ft_putendl_fd.o \
		ft_putnbr_fd.o \
		ft_lstnew.o \
		ft_lstadd_front.o \
		ft_lstsize.o \
		ft_lstlast.o \
		ft_lstadd_back.o \
		ft_lstdelone.o \
		ft_lstclear.o \
		ft_lstiter.o \
		ft_lstmap.o

SRCS = $(OBJS:.o=.c)
INCS = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
