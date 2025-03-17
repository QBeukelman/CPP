# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: quentinbeukelman <quentinbeukelman@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/17 21:57:55 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/03/17 22:09:08 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

NAME_EXECUTABLE = harl_complains

SRCS = main.cpp Harl.cpp utils.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME_EXECUTABLE)

$(NAME_EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME_EXECUTABLE) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(NAME_EXECUTABLE)

.PHONY: all clean
