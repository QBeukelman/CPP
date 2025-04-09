# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: quentin <quentin@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/24 22:36:42 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/04/09 16:34:04 by quentin       ########   odam.nl          #
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

NAME_EXECUTABLE			= fixed_point_exc

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)

# Targets
all: $(NAME_EXECUTABLE)

$(NAME_EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME_EXECUTABLE) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(BLUE)\nCleaning ...$(RESET)"
	@$(RM) -f $(OBJS)
	@echo "$(GREEN)$(BOLD)\nAll clean!\n$(RESET)"

fclean: clean
	@$(RM) -f $(NAME_EXECUTABLE)

re: fclean all

.PHONY: all clean
