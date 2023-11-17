CC = gcc
CFLAGS = -Werror -Wall -Wextra
SRC = ft_printf.c \
      ft_printf_int.c \
      ft_printf_string.c \
      ft_printf_unsigned_int.c \
	  ft_printf_adresse.c \
	  ft_printf_hex.c \
      ft_printf_char.c
OBJ = $(SRC:.c=.o)
LIBFT_OBJ = 1st-Project-Libft/*.o 
NAME = libftprintf.a

all: libft_bibliotheque $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ) $(LIBFT_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft_bibliotheque:
	$(MAKE) -C 1st-Project-Libft

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C 1st-Project-Libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C 1st-Project-Libft

re: fclean all
