NAME = fillit

SRC = src/solve_ll.c src/main.c src/solve_sh.c src/prnt.c src/mnp.c src/error.c src/env.c

OBJ = solve_ll.o main.o solve_sh.o prnt.o mnp.o error.o env.o

INC = -I ../filit.h

LIBFT =	libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
		gcc -Wall -Wextra -Werror -c $(SRC)

$(LIBFT):
		make -C ./libft/

clean:
		rm -f $(OBJ)
			make clean -C ./libft/

fclean: clean
		rm -f $(NAME)
			make fclean -C ./libft/

re: fclean all

.PHONY : all, re, clean, flcean
