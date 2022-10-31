NAME = libftprintf.a

SRCS =  ft_printf.c 	\
		f.c 			\
		f2.c 			

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS) 
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all
