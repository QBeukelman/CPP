# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 23:18:55 by quentinbeuk       #+#    #+#              #
#    Updated: 2025/04/11 11:13:13 by qbeukelm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD				:= \033[1m
RED					:= \033[31;1m
GREEN				:= \033[32;1m
YELLOW				:= \033[33;1m
BLUE				:= \033[34;1m
RESET				:= \033[0m

# Compiler
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

# Targets
FILENAME		= main.cpp
NAME_EXECUTABLE	= hi_this_is_brain_exc

all: $(NAME_EXECUTABLE)

$(NAME_EXECUTABLE): $(FILENAME)
	$(CC) $(CFLAGS) -o $(NAME_EXECUTABLE) $(FILENAME)

clean:
	@echo "$(BLUE)\nCleaning ...$(RESET)"
	@$(RM) -f $(OBJS)
	@echo "$(GREEN)$(BOLD)\nAll clean!\n$(RESET)"

fclean: clean
	@$(RM) -f $(NAME_EXECUTABLE)

re: fclean all

valgrind: $(NAME_EXECUTABLE)
	@echo "$(YELLOW)Running Valgrind...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME_EXECUTABLE)

.PHONY: all clean
