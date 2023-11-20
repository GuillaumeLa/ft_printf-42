CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c
OFILES = ft_printf.o
NAME=libftprintf.a


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES) 
	ar rcs $(NAME) $(OFILES) 

all: $(NAME) clean
clean:
	rm -f $(OFILES) 
fclean:  
	rm -f $(NAME)
re: fclean all

.PHONY : all clean fclean re 