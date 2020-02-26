NAME = fillit
C_FLS =	create_map.c fill_map.c fillit.c get_next_line.c get_tetriminos.c valid_mas.c f_check28.c
O_FLS = $(C_FLS:%.c=%.o)
COMP = gcc
FLAGS = -Wall -Wextra -Werror
HEAD = fillit.h
BIBL = ./libft
LIB_A = $(BIBL)/libft.a

all: $(NAME)

$(NAME): $(O_FLS)
	make -C $(BIBL)/ all
	$(COMP) $(FLAGS) -o $(NAME) $(O_FLS) $(LIB_A)

%.o: %.c $(HEAD)
	$(COMP) $(FLAGS) -c $(C_FLS)

clean:
	rm -f $(O_FLS)
	make -C $(BIBL)/ clean

fclean: clean
	rm -f $(NAME)
	make -C $(BIBL)/ fclean

re: fclean all

.PHONY: all clean fclean re