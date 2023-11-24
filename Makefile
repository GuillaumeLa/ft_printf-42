CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c ft_utils.c ft_utilshexa.c ft_utilsptr.c
OFILES = $(FILES:.c=.o)
NAME=libftprintf.a


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES) 
	ar rcs $(NAME) $(OFILES) 

all: $(NAME) clean
clean:
	rm -f $(OFILES) 
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY : all clean fclean re 