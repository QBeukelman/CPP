# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 11:41:32 by qbeukelm          #+#    #+#              #
#    Updated: 2025/03/14 11:53:10 by qbeukelm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD				:= \033[1m
RED					:= \033[31;1m
GREEN				:= \033[32;1m
YELLOW				:= \033[33;1m
BLUE				:= \033[34;1m
RESET				:= \033[0m

# Compiler
CC 		= g++
CFLAGS	= -Wall -Werror -Wextra -std=c++98

# Targets
SOURCES 		= Megaphone.cpp
NAME_EXECUTABLE	= megaphone

all: $(NAME_EXECUTABLE)

# Executable
$(NAME_EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $(NAME_EXECUTABLE) $(SOURCES)

valgrind: $(NAME_EXECUTABLE)
	@echo "$(YELLOW)Running Valgrind...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME_EXECUTABLE)

clean:
	@$(RM) $(NAME_EXECUTABLE)

fclean: clean
	@$(RM) $(NAME_EXECUTABLE)

re: fclean all

.PHONY: all clean
