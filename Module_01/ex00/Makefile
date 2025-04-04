# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 21:11:13 by quentinbeuk       #+#    #+#              #
#    Updated: 2025/04/04 17:24:30 by qbeukelm         ###   ########.fr        #
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

NAME_EXECUTABLE = zombie_exc

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME_EXECUTABLE)

$(NAME_EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME_EXECUTABLE) $(OBJS)

%.o: %.cpp Zombie.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean: all
	@echo "$(BLUE)\nCleaning ...$(RESET)"
	@$(RM) -rf $(OBJS)
	@echo "$(GREEN)$(BOLD)\nAll clean!\n$(RESET)"

fclean: clean
	@$(RM) $(NAME_EXECUTABLE)

re: fclean all

.PHONY: all clean
