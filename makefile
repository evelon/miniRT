.DEFAULT_GOAL := help
.PHONY: clean fclean all re test

CC = gcc
AR = ar
ARFLAGS = rcsv

CFLAGS = -Wall -Werror -Wextra
LFLAGS = $(addprefix -l, $(DIRS))

NAME = miniRT

RT = rt
LIBFT = libft
GNL = get_next_line
DIRS = $(RT) $(LIBFT) $(GNL)
LIBS = $(addsuffix .a, $(addprefix lib, $(DIRS)))

all: ## run makefile
	make -C ./libft
	make -C ./get_next_line
	make -C ./rt
	$(CC) $(CFLAGS) -g3 -fsanitize=address -lmlx -framework OpenGL -framework AppKit -L. $(LFLAGS) -o $(NAME)

clean: ## delete all files made by makefile except for the executable
	make -C ./$(RT) fclean
	make -C ./$(GNL) fclean
	make -C ./$(LIBFT) fclean

fclean: clean ## delete all files made by makefile
	rm -rf $(NAME)

re: fclean all ## delete all files include the executable and make

test: all ## make and run rt.out with a test file.
	./$(NAME) "sub1.rt"

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'