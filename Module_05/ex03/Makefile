# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: quentinbeukelman <quentinbeukelman@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2025/06/20 08:36:09 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/06/20 08:40:43 by quentinbeuk   ########   odam.nl          #
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
CFLAGS = -std=c++11 -Wall -Werror -Wextra

# Targets
NAME_EXECUTABLE = bureaucrat_exc

# Sources
SOURCES						= main.cpp

SOURCES_BUREAUCRAT			= Bureaucrat.cpp \
								AForm.cpp \
								helpers.cpp \
								Intern.cpp \
								PresidentialPardonForm.cpp \
								RobotomyRequestForm.cpp \
								ShrubberyCreationForm.cpp \

INC 						= inc
DIR_OBJ						= obj

# Directories
DIR_SOURCES					= .
DIR_SOURCES_BUREAUCRAT		= sources


# Object files
OBJ = $(addprefix $(DIR_OBJ)/, $(SOURCES:.cpp=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_BUREAUCRAT:.cpp=.o)) \

all: $(NAME_EXECUTABLE)

$(NAME_EXECUTABLE): $(OBJ)
	@echo "$(BLUE)\nMaking ...\n$(RESET)"
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME_EXECUTABLE)
	@echo "$(GREEN)Compiled all!\n$(RESET)"

$(DIR_OBJ)/%.o: $(DIR_SOURCES)/%.cpp | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_BUREAUCRAT)/%.cpp | $(DIR_OBJ)
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
	@$(RM) -f $(NAME_EXECUTABLE)

re: fclean all

valgrind: $(NAME_EXECUTABLE)
	@echo "$(YELLOW)Running Valgrind...$(RESET)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME_EXECUTABLE)

.PHONY: all clean fclean re valgrind
