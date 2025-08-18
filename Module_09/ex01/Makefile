# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qbeukelm <qbeukelm@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2025/07/08 07:58:18 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/08/18 13:43:40 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

RED				:= \033[31;1m
GREEN			:= \033[32;1m
YELLOW			:= \033[33;1m
BLUE			:= \033[34;1m
RESET			:= \033[0m

# Compiler
CXX       := c++
CXXFLAGS  := -std=c++17 -Wall -Werror -Wextra -MMD -MP -Iinc

# Target
NAME      := RPN

# Dirs
DIR_OBJ   := obj

# Sources
SOURCES := \
main.cpp \
sources/RPN.cpp \

OBJECTS := $(patsubst %.cpp,$(DIR_OBJ)/%.o,$(SOURCES))
DEPENDS := $(OBJECTS:.o=.d)

all: $(NAME)

# Link
$(NAME): $(OBJECTS)
	@echo "$(BLUE)\nLinking $(NAME)...$(RESET)"
	@$(CXX) $(OBJECTS) -o $@
	@echo "$(GREEN)\nDone\n$(RESET)"

# Compile
$(DIR_OBJ)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)\nCleaning ...$(RESET)"
	@rm -rf $(DIR_OBJ)
	@echo "$(GREEN)$(BOLD)\nAll clean!\n$(RESET)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPENDS)

.PHONY: all clean fclean re
