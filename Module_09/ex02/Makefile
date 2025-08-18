# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qbeukelm <qbeukelm@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2025/07/09 08:47:12 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/08/18 13:59:41 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


BOLD				:= \033[1m
RED					:= \033[31;1m
GREEN				:= \033[32;1m
YELLOW				:= \033[33;1m
BLUE				:= \033[34;1m
RESET				:= \033[0m

# Compiler
CXX       := c++
CXXFLAGS  := -std=c++17 -Wall -Werror -Wextra -MMD -MP -Iinc

# Targets
NAME                  := PmergeMe
NAME_NUMBER_GENERATOR := generator

# Dirs
DIR_OBJ := obj

# ---- Explicit sources for each executable ----
SRCS_MAIN := \
main.cpp \
sources/PmergeMe.cpp \
sources/PmergeMeDeque.cpp \
sources/writer.cpp

SRCS_GEN := \
sources/generator.cpp

# Objects/Deps
OBJS_MAIN := $(patsubst %.cpp,$(DIR_OBJ)/%.o,$(SRCS_MAIN))
OBJS_GEN  := $(patsubst %.cpp,$(DIR_OBJ)/%.o,$(SRCS_GEN))

DEPS := $(OBJS_MAIN:.o=.d) $(OBJS_GEN:.o=.d)

all: $(NAME)

# Link
$(NAME): $(OBJS_MAIN)
	@$(CXX) $(OBJS_MAIN) -o $@

$(NAME_NUMBER_GENERATOR): $(OBJS_GEN)
	@$(CXX) $(OBJS_GEN) -o $@

# Compile
$(DIR_OBJ)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Build generator
generator-build: $(NAME_NUMBER_GENERATOR)

clean:
	@rm -rf $(DIR_OBJ)
	@rm -f $(NAME_NUMBER_GENERATOR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re generator-build
