NAME = test

CC = gcc

SRCS_DIR = srcs/

OBJS_DIR = objs/

# SRCS_FIL = main.c hooks.c bresenham.c
SRCS_FIL = test.c helper.c

SRCS := $(addprefix $(SRCS_DIR), $(SRCS_FIL))

HEADER = ./includes/

INCLUDES = -I$(HEADER) -I$(LIBFT_DIR)

# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

LIBRARIES =  -L$(LIBFT_DIR) -lft -lreadline -v

LIBFT_DIR = ./libft/

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FIL:.c=.o))

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) ${INCLUDES} -c $< -o $@


$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBRARIES) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

format:
	@$(foreach file, $(wildcard $(SRCS_DIR)*), c_formatter_42 $(file);)

libft:
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)

fclean:
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)

re: fclean all 

norm:
	@Norminette -R CheckDefine

# rotate_art:
# 	@sleep 0.2 && echo ${ART1}
# 	@sleep 0.2 && echo -e "\033[2J\033[H"
# 	@sleep 0.2 && echo ${ART2}
# 	@sleep 0.2 && echo -e "\033[2J\033[H"
# 	@sleep 0.2 && echo ${ART1}
# 	@sleep 0.2 && echo -e "\033[2J\033[H"
# 	@sleep 0.2 && echo ${ART2}

.PHONY: all clean fclean re norm format

# # @echo -e "\033[2J\033[1;1H"
# # 	@echo -e "\033[9A\033[K"
# # 	@tput clear || printf "\033c"
# DEF_COLOR='\033[0;39m'
# BLACK='\033[0;30m'
# RED='\033[1;91m'
# GREEN='\033[1;92m'
# YELLOW='\033[0;93m'
# BLUE='\033[0;94m'
# MAGENTA='\033[0;95m'
# CYAN='\033[0;96m'
# GRAY='\033[0;90m'
# WHITE='\033[0;97m'
# ORANGE='\033[38;5;208m'
#
#
# ART1 = \n \
# ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣷⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n \
# ⠀⠀⠀⠀⠀⠀⠀⣀⣶⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣦⣀⡀⠀⢀⣴⣇⠀⠀⠀⠀ \n \
# ⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀ \n \
# ⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀ \n \
# ⠀⠀⠀⣴⣿⣿⣿⣿⠛⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣄⠀⠀⠀⠀ \n \
# ⠀⠀⣾⣿⣿⣿⣿⣿⣶⣿⣯⣭⣬⣉⣽⣿⣿⣄⣼⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀ \n \
# ⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀ \n \
# ⢸⣿⣿⣿⣿⠟⠋⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⣿⣿⣿⣿⡿⠛⠉⠉⠉⠉⠁ \n \
# ⠘⠛⠛⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠛⠃⠀⠀⠀⠀⠀ \n
#
# ART2 = \n \
# ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n \
# ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n \
# ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣶⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n \
# ⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣄⣀⡀⣠⣾⡇⠀⠀⠀⠀ \n \
# ⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀ \n \
# ⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⡇⠀⠀⠀⠀⠀ \n \
# ⠀⣶⣿⣦⣜⣿⣿⣿⡟⠻⣿⣿⣿⣿⣿⣿⣿⡿⢿⡏⣴⣺⣦⣙⣿⣷⣄⠀⠀⠀ \n \
# ⠀⣯⡇⣻⣿⣿⣿⣿⣷⣾⣿⣬⣥⣭⣽⣿⣿⣧⣼⡇⣯⣇⣹⣿⣿⣿⣿⣧⠀⠀ \n \
# ⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠸⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀ \n
#
#
# ART = ${ART1} ${ART2}
