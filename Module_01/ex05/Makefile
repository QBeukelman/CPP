# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 21:57:55 by quentinbeuk       #+#    #+#              #
#    Updated: 2025/04/04 17:17:11 by qbeukelm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD				:= \033[1m
RED					:= \033[31;1m
GREEN				:= \033[32;1m
YELLOW				:= \033[33;1m
BLUE				:= \033[34;1m
RESET				:= \033[0m

# Compileer
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

# Target
NAME_EXECUTABLE = harl_complains_exc

SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME_EXECUTABLE)

$(NAME_EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME_EXECUTABLE) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean: all
	@echo "$(BLUE)\nCleaning ...$(RESET)"
	@$(RM) -rf $(OBJS)
	@echo "$(GREEN)$(BOLD)\nAll clean!\n$(RESET)"

fclean: clean
	@$(RM) $(NAME_EXECUTABLE)

re: fclean all

.PHONY: all clean