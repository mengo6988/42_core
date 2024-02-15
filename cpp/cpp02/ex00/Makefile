NAME = Harl

CC = c++

SRCS_DIR = srcs/

OBJS_DIR = objs/

SRCS_FIL = main.cpp Fixed.cpp

SRCS := $(addprefix $(SRCS_DIR), $(SRCS_FIL))

HEADER = ./includes/

CFLAGS = -Wall -Wextra -Werror -std=c++98

OPTION = -I $(HEADER)

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FIL:.cpp=.o))


all: $(OBJS_DIR) $(NAME)


$(BOBJS_DIR):
	@mkdir -p $(BOBJS_DIR)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)


$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp | $(OBJS_DIR)
	@$(CC) $(CFLAGS) ${OPTION} -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean:
	@rm -rf $(OBJS_DIR) $(BOBJS_DIR)


fclean:
	@rm -rf $(OBJS_DIR) $(BOBJS_DIR)
	@rm -f $(NAME) $(BONUS)


re: fclean all

norm:
	@norminette -R CheckDefine


.PHONY: all clean fclean re rotate_art clean_loader fclean_loader builder fcleans 

