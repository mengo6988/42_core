NAME = libftprintf.a

LIBFT = libft.a

CC = gcc

SRCS_DIR = srcs/

OBJS_DIR = objs/

SRCS_FIL = check_flags.c ft_printf.c print_i.c print_p.c \
			print_str.c print_u.c print_x.c

SRCS := $(addprefix $(SRCS_DIR), $(SRCS_FIL))

# HEADER = ./includes/

CFLAGS = -Wall -Wextra -Werror

OPTION = -I $(HEADER)

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FIL:.c=.o))

LIBFT_DIR = ./libft

all:
		mkdir -p $(OBJS_DIR)
		make $(NAME)

bonus:
		mkdir -p $(OBJS_DIR)
		make $(NAME)

#$(OBJS): $(SRCS)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
			ar -rcs $(NAME) $(OBJS)

$(LIBFT):
		make -C $(LIBFT_DIR)
		cp $(LIBFT_DIR)/$(LIBFT) .
		mv $(LIBFT) $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
