# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: quentinbeukelman <quentinbeukelman@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/16 21:11:50 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/03/17 20:56:54 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME_EXECUTABLE = string_replace

SRCS = main.cpp File.cpp StringProcessor.cpp utils.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME_EXECUTABLE)

$(NAME_EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME_EXECUTABLE) $(OBJS)

%.o: %.cpp Zombie.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(NAME_EXECUTABLE)

.PHONY: all clean
