# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qbeukelm <qbeukelm@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/14 14:06:21 by qbeukelm      #+#    #+#                  #
#    Updated: 2025/03/16 15:37:13 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BOLD				:= \033[1m
RED					:= \033[31;1m
GREEN				:= \033[32;1m
YELLOW				:= \033[33;1m
BLUE				:= \033[34;1m
RESET				:= \033[0m

# Compiler
CC = g++
CFLAGS = -std=c++98 # -Wall -Werror -Wextra

# Targets
NAME_EXECUTABLE = unnecessary_violance

# Sources
SOURCES						= main.cpp \

SOURCES_HUMAN				= HumanA.cpp \
								HumanB.cpp \

SOURCES_WEAPON				= Weapon.cpp \

INC 						= inc
DIR_OBJ						= obj

# Directories
DIR_SOURCES					= sources
DIR_SOURCES_HUMAN			= sources/human
DIR_SOURCES_WEAPON			= sources/weapon

# Object files
OBJ = $(addprefix $(DIR_OBJ)/, $(SOURCES:.cpp=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_HUMAN:.cpp=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_WEAPON:.cpp=.o))

all: $(NAME_EXECUTABLE)

$(NAME_EXECUTABLE): $(OBJ)
	@echo "$(BLUE)Making ...\n$(RESET)"
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME_EXECUTABLE)
	@echo "$(GREEN)Compiled all!\n$(RESET)"

$(DIR_OBJ)/%.o: $(DIR_SOURCES)/%.cpp | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_HUMAN)/%.cpp | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_WEAPON)/%.cpp | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ):
	@mkdir -p $@

clean:
	@echo "$(BLUE)\nCleaning ...$(RESET)"
	@$(RM) -rf $(DIR_OBJ)
	@$(RM) -rf $(EXTRA_O)
	@$(RM) -rf $(OBJS)
	@echo "$(GREEN)$(BOLD)\nAll clean!\n$(RESET)"

fclean: clean
	@$(RM) $(NAME_EXECUTABLE)

re: fclean all

valgrind: $(NAME_EXECUTABLE)
	@echo "$(YELLOW)Running Valgrind...$(RESET)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME_EXECUTABLE)

.PHONY: all clean fclean re valgrind
