# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 23:19:04 by quentinbeuk       #+#    #+#              #
#    Updated: 2025/04/11 11:13:03 by qbeukelm         ###   ########.fr        #
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

NAME_EXECUTABLE			= zombie_exc

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp testZombie.cpp zombieHorde.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME_EXECUTABLE)

$(NAME_EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME_EXECUTABLE) $(OBJS)

%.o: %.cpp Zombie.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

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
