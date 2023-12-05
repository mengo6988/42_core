NAME = push_swap

LIBFT = libft.a

CC = gcc

SRCS_DIR = srcs/

OBJS_DIR = objs/

SRCS_FIL = chunk_util.c data_io.c main.c move.c op_lst_util.c print.c push.c reverse_rotate.c rotate.c \
		simple_sort.c small_arr_op.c sort_three_op.c sort_utils.c sort.c stack_init.c stack_utils.c swap.c

SRCS := $(addprefix $(SRCS_DIR), $(SRCS_FIL))

HEADER = ./includes/

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

OPTION = -I $(HEADER)

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FIL:.c=.o))

LIBFT_DIR = ./libft

all: $(OBJS_DIR) $(NAME)
	@ echo "███╗   ███╗ █████╗ ██╗  ██╗███████╗    ██████╗  ██████╗ ███╗   ██╗███████╗"
	@ echo "████╗ ████║██╔══██╗██║ ██╔╝██╔════╝    ██╔══██╗██╔═══██╗████╗  ██║██╔════╝"
	@ echo "██╔████╔██║███████║█████╔╝ █████╗      ██║  ██║██║   ██║██╔██╗ ██║█████╗  "
	@ echo "██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝      ██║  ██║██║   ██║██║╚██╗██║██╔══╝  "
	@ echo "██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗    ██████╔╝╚██████╔╝██║ ╚████║███████╗"
	@ echo "╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝╚══════╝"
	@ echo " "


# bonus:
# 	@mkdir -p $(OBJS_DIR)
# 	@make $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

#$(OBJS): $(SRCS)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) ${OPTION} -c $< -o $@

# $(NAME): $(OBJS) $(LIBFT)
# 	@ar -rcs $(NAME) $(OBJS)
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@mv $(LIBFT) $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@echo " ██████╗██╗     ███████╗ █████╗ ███╗   ██╗    ██████╗  ██████╗ ███╗   ██╗███████╗"
	@echo "██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║    ██╔══██╗██╔═══██╗████╗  ██║██╔════╝"
	@echo "██║     ██║     █████╗  ███████║██╔██╗ ██║    ██║  ██║██║   ██║██╔██╗ ██║█████╗  "
	@echo "██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║    ██║  ██║██║   ██║██║╚██╗██║██╔══╝  "
	@echo "╚██████╗███████╗███████╗██║  ██║██║ ╚████║    ██████╔╝╚██████╔╝██║ ╚████║███████╗"
	@echo " ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝╚══════╝"
	@echo " "

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "███████╗ ██████╗██╗     ███████╗ █████╗ ███╗   ██╗    ██████╗  ██████╗ ███╗   ██╗███████╗"
	@echo "██╔════╝██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║    ██╔══██╗██╔═══██╗████╗  ██║██╔════╝"
	@echo "█████╗  ██║     ██║     █████╗  ███████║██╔██╗ ██║    ██║  ██║██║   ██║██╔██╗ ██║█████╗  "
	@echo "██╔══╝  ██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║    ██║  ██║██║   ██║██║╚██╗██║██╔══╝  "
	@echo "██║     ╚██████╗███████╗███████╗██║  ██║██║ ╚████║    ██████╔╝╚██████╔╝██║ ╚████║███████╗"
	@echo "╚═╝      ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝╚══════╝"
	@echo " "

re: fclean all

.PHONY: all clean fclean re
