# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 16:29:13 by adbenoit          #+#    #+#              #
#    Updated: 2022/07/14 18:05:17 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror #-fsanitize=address -g3
IFLAGS 	= -I./incs

HOST	= localhost

# DIRECTORIES
BUILD 			:= .build
SRC_DIR 		:= srcs
OBJ_DIR 		:= $(BUILD)/obj
SUB_DIR			:= 
DIRS			:= $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))


# FILES
NAME			:= ft_ping
SRC				:=	main.c \
					error.c \
					signal.c \
					stats.c \
					parser.c \
					utils.c \
					request.c \
					response.c \
					socket.c \
					time.c \
					math.c \
					debug.c
SUB_SRC			:= 
# SRC				+= $(addprefix {name}, $(SUB_SRC))

OBJ				:= $(SRC:%.c=$(OBJ_DIR)/%.o)


# COLORS
NONE			= \033[0m
CL_LINE			= \033[2K
B_RED			= \033[1;31m
B_GREEN			= \033[1;32m
B_GREY	 		= \033[1;38m
B_MAGENTA 		= \033[1;35m
B_CYAN 			= \033[1;36m
B_BLUE 			= \033[1;34m
B_YELLOW 		= \033[1;33m
B_WHITE 		= \033[1;37m


# MAKEFILE
$(NAME): $(OBJ)
	@printf "$(CL_LINE)"
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "[1 / 1] - $(B_MAGENTA)$@"
	@echo "$(B_GREEN)Compilation done !$(NONE)"

all: $(NAME)

clean:
	@rm -Rf $(BUILD)
	@echo "$(B_GREY)$(BUILD)$(NONE): $(B_YELLOW)Delete$(NONE)"

fclean: clean
	@rm -Rf $(NAME)
	@echo "$(B_GREY)$(NAME)$(NONE): $(B_YELLOW)Delete$(NONE)"

re: fclean all

run: debug
	@echo
	@echo "    ____________   ____  _____   ________"
	@echo "   / ____/_  __/  / __ \/  _/ | / / ____/"
	@echo "  / /_    / /    / /_/ // //  |/ / / __  "
	@echo " / __/   / /    / ____// // /|  / /_/ /  "
	@echo "/_/     /_/____/_/   /___/_/ |_/\____/   "
	@echo "         /_____/                         "
	@echo
	@sudo ./$(NAME) $(HOST)

debug: CFLAGS += -DDEBUG
debug: os

os: CFLAGS += -DOS
os: re
	
.PHONY: all clean fclean re debug

$(BUILD):
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c ./incs/ft_ping.h | $(BUILD)
	@printf "$(CL_LINE)Compiling srcs object : $(B_CYAN)$< $(NONE)...\r"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
