# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qbeukelm <qbeukelm@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2025/07/08 07:58:18 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/08/05 09:27:20 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

RED				:= \033[31;1m
GREEN			:= \033[32;1m
YELLOW			:= \033[33;1m
BLUE			:= \033[34;1m
RESET			:= \033[0m

# Compiler
CC = c++
CFLAGS = -std=c++17 -Wall -Werror -Wextra

# Targets
NAME_EXECUTABLE = RPN

# Sources
SOURCES			= main.cpp
SOURCES_RPN		= RPN.cpp

# Directories
INC				= inc
DIR_OBJ			= obj
DIR_SOURCES		= .
DIR_SOURCES_RPN	= sources

# VPATH for source lookup
VPATH = $(DIR_SOURCES):$(DIR_SOURCES_RPN)

# Object files
OBJ = $(addprefix $(DIR_OBJ)/, $(SOURCES:.cpp=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RPN:.cpp=.o))

# Build target
all: $(NAME_EXECUTABLE)

$(NAME_EXECUTABLE): $(OBJ)
	@echo "$(BLUE)\nMaking ...\n$(RESET)"
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME_EXECUTABLE)
	@echo "$(GREEN)Compiled all!\n$(RESET)"

# Compile rules
$(DIR_OBJ)/%.o: %.cpp | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ):
	@mkdir -p $@

clean:
	@echo "$(BLUE)\nCleaning ...$(RESET)"
	@$(RM) -rf $(DIR_OBJ)
	@echo "$(GREEN)$(BOLD)\nAll clean!\n$(RESET)"

fclean: clean
	@$(RM) -f $(NAME_EXECUTABLE)

re: fclean all

valgrind: $(NAME_EXECUTABLE)
	@echo "$(YELLOW)Running Valgrind...$(RESET)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME_EXECUTABLE)

.PHONY: all clean fclean re valgrind
