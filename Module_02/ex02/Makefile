# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: quentinbeukelman <quentinbeukelman@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/24 22:36:42 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/03/24 22:36:49 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = g++

CFLAGS = -Wall -Werror -Wextra -std=c++98

TARGET			= fixed_point

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)

# Targets
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp Fixed.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
