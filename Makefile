NAME = ft_printf.a

SRCS = f.c f2.c ft_printf.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS) 
clean:
	rm -f $(OBJS) $(NAME)
fclean: clean
	rm -f $(NAME)

re: fclean all
