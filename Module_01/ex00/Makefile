# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: quentinbeukelman <quentinbeukelman@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/16 21:11:13 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/03/17 23:32:06 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME_EXECUTABLE = zombie
UTILS			= ../utils/utils.cpp

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp ../utils/utils.cpp $(UTILS)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME_EXECUTABLE)

$(NAME_EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME_EXECUTABLE) $(OBJS)

%.o: %.cpp Zombie.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(NAME_EXECUTABLE)

.PHONY: all clean
