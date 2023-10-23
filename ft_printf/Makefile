NAME = libft.a

CC = gcc

SRCS_DIR = srcs/

SRCS_FIL =

SRCS := $(addprefix $(SRCS_DIR), $(SRCS_FIL))

BONUS_FIL =

BONUS := $(addprefix $(SRCS_DIR), $(BONUS_FIL))

HEADER = ./includes/

CFLAGS = -Wall -Wextra -Werror -std=c99

OPTION = -I $(HEADER)

OBJS = $(SRCS:.c=.o)

BOBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

#$(OBJS): $(SRCS)
%.o: %.c
	$(CC) $(CFLAGS) $(OPTION) -c $< -o $@

bonus: $(OBJS) $(BOBJS)
	ar -rc $(NAME) $(BOBJS) $(OBJS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
