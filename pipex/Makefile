DEF_COLOR='\033[0;39m'
BLACK='\033[0;30m'
RED='\033[1;91m'
GREEN='\033[1;92m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
MAGENTA='\033[0;95m'
CYAN='\033[0;96m'
GRAY='\033[0;90m'
WHITE='\033[0;97m'
ORANGE='\033[38;5;208m'


ART1 = \n \
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣷⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n \
⠀⠀⠀⠀⠀⠀⠀⣀⣶⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣦⣀⡀⠀⢀⣴⣇⠀⠀⠀⠀ \n \
⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀ \n \
⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀ \n \
⠀⠀⠀⣴⣿⣿⣿⣿⠛⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣄⠀⠀⠀⠀ \n \
⠀⠀⣾⣿⣿⣿⣿⣿⣶⣿⣯⣭⣬⣉⣽⣿⣿⣄⣼⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀ \n \
⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀ \n \
⢸⣿⣿⣿⣿⠟⠋⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⣿⣿⣿⣿⡿⠛⠉⠉⠉⠉⠁ \n \
⠘⠛⠛⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠛⠃⠀⠀⠀⠀⠀ \n

ART2 = \n \
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n \
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n \
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣶⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n \
⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣄⣀⡀⣠⣾⡇⠀⠀⠀⠀ \n \
⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀ \n \
⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⡇⠀⠀⠀⠀⠀ \n \
⠀⣶⣿⣦⣜⣿⣿⣿⡟⠻⣿⣿⣿⣿⣿⣿⣿⡿⢿⡏⣴⣺⣦⣙⣿⣷⣄⠀⠀⠀ \n \
⠀⣯⡇⣻⣿⣿⣿⣿⣷⣾⣿⣬⣥⣭⣽⣿⣿⣧⣼⡇⣯⣇⣹⣿⣿⣿⣿⣧⠀⠀ \n \
⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠸⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀ \n


ART = ${ART1} ${ART2}

NAME = pipex

LIBFT = libft.a

CC = gcc

SRCS_DIR = srcs/

OBJS_DIR = objs/

SRCS_FIL = test.c

SRCS := $(addprefix $(SRCS_DIR), $(SRCS_FIL))

HEADER = ./includes/

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

OPTION = -I $(HEADER)

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FIL:.c=.o))

LIBFT_DIR = ./libft

# all: $(OBJS_DIR) $(NAME) builder complete
all: $(OBJS_DIR) $(NAME)

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

# clean: clean_loader complete
clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)


# fclean: fclean_loader complete
fclean:
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)

fcleans: fclean_loader
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)

re: fcleans all complete

# rotate_art:
# 	@sleep 0.2 && echo ${ART1}
# 	@sleep 0.2 && echo -e "\033[2J\033[H"
# 	@sleep 0.2 && echo ${ART2}
# 	@sleep 0.2 && echo -e "\033[2J\033[H"
# 	@sleep 0.2 && echo ${ART1}
# 	@sleep 0.2 && echo -e "\033[2J\033[H"
# 	@sleep 0.2 && echo ${ART2}

builder:
	@echo ${GREEN}":::::::::  :::    ::: ::::::::::: :::        ::::::::: ::::::::::: ::::    :::  ::::::::              "${DEF_COLOR}
	@echo ${GREEN}":+:    :+: :+:    :+:     :+:     :+:        :+:    :+:    :+:     :+:+:   :+: :+:    :+:             "${DEF_COLOR}
	@echo ${GREEN}"+:+    +:+ +:+    +:+     +:+     +:+        +:+    +:+    +:+     :+:+:+  +:+ +:+                    "${DEF_COLOR}
	@echo ${GREEN}"+#++:++#+  +#+    +:+     +#+     +#+        +#+    +:+    +#+     +#+ +:+ +#+ :#:                    "${DEF_COLOR}
	@echo ${CYAN}"+#+    +#+ +#+    +#+     +#+     +#+        +#+    +#+    +#+     +#+  +#+#+# +#+   +#+#             "${DEF_COLOR}
	@echo ${CYAN}"#+#    #+# #+#    #+#     #+#     #+#        #+#    #+#    #+#     #+#   #+#+# #+#    #+# #+# #+# #+# "${DEF_COLOR}
	@echo ${CYAN}"#########   ########  ########### ########## ######### ########### ###    ####  ########  ### ### ### "${DEF_COLOR}
	@echo "\n"
	@sleep 0.5 &&	echo ${CYAN}"\033[2J\033[H${ART1}Cleaning in progress.. ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 0%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${CYAN}"\033[2J\033[H${ART2}Cleaning in progress.. █████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 10%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${CYAN}"\033[2J\033[H${ART1}Cleaning in progress.. ████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 20%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${CYAN}"\033[2J\033[H${ART2}Cleaning in progress.. ███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 30%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${CYAN}"\033[2J\033[H${ART1}Cleaning in progress.. ██████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 40%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${CYAN}"\033[2J\033[H${ART2}Cleaning in progress.. █████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 50%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${CYAN}"\033[2J\033[H${ART1}Cleaning in progress.. ████████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 60%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${CYAN}"\033[2J\033[H${ART2}Cleaning in progress.. ███████████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 70%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${CYAN}"\033[2J\033[H${ART1}Cleaning in progress.. ███████████████████████████████▒▒▒▒▒▒▒▒▒ 80%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${CYAN}"\033[2J\033[H${ART2}Cleaning in progress.. ███████████████████████████████████▒▒▒▒▒ 90%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${CYAN}"\033[2J\033[H${ART1}Cleaning in progress.. ████████████████████████████████████████ 100%"${DEF_COLOR}
	@sleep 0.2 &&	echo "\033[2J\033[H"

clean_loader:
	@echo "\n"
	@echo ${BLUE}" ::::::::  :::        ::::::::::     :::     ::::    ::: ::::::::::: ::::    :::  ::::::::              "${DEF_COLOR}
	@echo ${BLUE}":+:    :+: :+:        :+:          :+: :+:   :+:+:   :+:     :+:     :+:+:   :+: :+:    :+:             "${DEF_COLOR}
	@echo ${BLUE}":+:        +:+        +:+         +:+   +:+  :+:+:+  +:+     +:+     :+:+:+  +:+ +:+                    "${DEF_COLOR}
	@echo ${BLUE}"+#+        +#+        +#++:++#   +#++:++#++: +#+ +:+ +#+     +#+     +#+ +:+ +#+ :#:                    "${DEF_COLOR}
	@echo ${CYAN}"+#+        +#+        +#+        +#+     +#+ +#+  +#+#+#     +#+     +#+  +#+#+# +#+   +#+#             "${DEF_COLOR}
	@echo ${CYAN}"#+#    #+# #+#        #+#        #+#     #+# #+#   #+#+#     #+#     #+#   #+#+# #+#    #+# #+# #+# #+# "${DEF_COLOR}
	@echo ${CYAN}" ########  ########## ########## ###     ### ###    #### ########### ###    ####  ########  ### ### ###  "${DEF_COLOR}
	@echo "\n"
	@sleep 0.5 &&	echo ${BLUE}"\033[2J\033[H${ART1}Cleaning in progress.. ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 0%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${BLUE}"\033[2J\033[H${ART2}Cleaning in progress.. █████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 10%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${BLUE}"\033[2J\033[H${ART1}Cleaning in progress.. ████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 20%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${BLUE}"\033[2J\033[H${ART2}Cleaning in progress.. ███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 30%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${BLUE}"\033[2J\033[H${ART1}Cleaning in progress.. ██████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 40%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${BLUE}"\033[2J\033[H${ART2}Cleaning in progress.. █████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 50%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${BLUE}"\033[2J\033[H${ART1}Cleaning in progress.. ████████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 60%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${BLUE}"\033[2J\033[H${ART2}Cleaning in progress.. ███████████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 70%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${BLUE}"\033[2J\033[H${ART1}Cleaning in progress.. ███████████████████████████████▒▒▒▒▒▒▒▒▒ 80%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${BLUE}"\033[2J\033[H${ART2}Cleaning in progress.. ███████████████████████████████████▒▒▒▒▒ 90%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${BLUE}"\033[2J\033[H${ART1}Cleaning in progress.. ████████████████████████████████████████ 100%"${DEF_COLOR}
	@sleep 0.2 &&	echo "\033[2J\033[H"


fclean_loader:
	@echo "\n"
	@echo ${MAGENTA}":::::::::: ::::::::  :::        ::::::::::     :::     ::::    :::         "
	@echo ${MAGENTA}":+:       :+:    :+: :+:        :+:          :+: :+:   :+:+:   :+:         "
	@echo ${MAGENTA}"+:+       +:+        +:+        +:+         +:+   +:+  :+:+:+  +:+         "
	@echo ${MAGENTA}":#::+::#  +#+        +#+        +#++:++#   +#++:++#++: +#+ +:+ +#+         "
	@echo ${GRAY}"+#+       +#+        +#+        +#+        +#+     +#+ +#+  +#+#+#         "
	@echo ${GRAY}"#+#       #+#    #+# #+#        #+#        #+#     #+# #+#   #+#+# #+# #+# #+# "
	@echo ${GRAY}"###        ########  ########## ########## ###     ### ###    #### ### ### ###  "
	@echo "\n"
	@sleep 0.5 &&	echo ${MAGENTA}"\033[2J\033[H${ART1}Cleaning in progress.. ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 0%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${MAGENTA}"\033[2J\033[H${ART2}Cleaning in progress.. █████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 10%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${MAGENTA}"\033[2J\033[H${ART1}Cleaning in progress.. ████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 20%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${MAGENTA}"\033[2J\033[H${ART2}Cleaning in progress.. ███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 30%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${MAGENTA}"\033[2J\033[H${ART1}Cleaning in progress.. ██████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 40%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${MAGENTA}"\033[2J\033[H${ART2}Cleaning in progress.. █████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 50%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${MAGENTA}"\033[2J\033[H${ART1}Cleaning in progress.. ████████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 60%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${MAGENTA}"\033[2J\033[H${ART2}Cleaning in progress.. ███████████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 70%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${MAGENTA}"\033[2J\033[H${ART1}Cleaning in progress.. ███████████████████████████████▒▒▒▒▒▒▒▒▒ 80%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${MAGENTA}"\033[2J\033[H${ART2}Cleaning in progress.. ███████████████████████████████████▒▒▒▒▒ 90%"${DEF_COLOR}
	@sleep 0.2 &&	echo ${MAGENTA}"\033[2J\033[H${ART1}Cleaning in progress.. ████████████████████████████████████████ 100%"${DEF_COLOR}
	@sleep 0.2 &&	echo "\033[2J\033[H"



complete:
	@echo "\n"
	@echo ${GREEN}" ::::::::   ::::::::  ::::    ::::  :::::::::  :::        :::::::::: ::::::::::: :::::::::: ::: "${DEF_COLOR}
	@echo ${GREEN}":+:    :+: :+:    :+: +:+:+: :+:+:+ :+:    :+: :+:        :+:            :+:     :+:        :+: "${DEF_COLOR}
	@echo ${GREEN}"+:+        +:+    +:+ +:+ +:+:+ +:+ +:+    +:+ +:+        +:+            +:+     +:+        +:+ "${DEF_COLOR}
	@echo ${GREEN}"+#+        +#+    +#+ +#+  +:+  +#+ +#++:++#+  +#+        +#++:++#       +#+     +#++:++#   +#+ "${DEF_COLOR}
	@echo ${GREEN}"+#+        +#+    +#+ +#+       +#+ +#+        +#+        +#+            +#+     +#+        +#+ "${DEF_COLOR}
	@echo ${GREEN}"#+#    #+# #+#    #+# #+#       #+# #+#        #+#        #+#            #+#     #+#            "${DEF_COLOR}
	@echo ${GREEN}" ########   ########  ###       ### ###        ########## ##########     ###     ########## ### "${DEF_COLOR}
	@echo "\n"
	@sleep 0.8 &&	echo "\033[2J\033[H"

.PHONY: all clean fclean re rotate_art clean_loader fclean_loader builder fcleans

# @echo -e "\033[2J\033[1;1H"
# 	@echo -e "\033[9A\033[K"
# 	@tput clear || printf "\033c"
