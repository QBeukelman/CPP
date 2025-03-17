# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: quentinbeukelman <quentinbeukelman@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/17 23:18:55 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/03/17 23:34:16 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

# Targets
UTILS			= ../utils/utils.cpp
FILENAME		= main.cpp $(UTILS)
TARGET			= hi_this_is_brain

all: $(TARGET)

# Executable
$(TARGET): $(FILENAME)
	$(CC) $(CFLAGS) -o $(TARGET) $(FILENAME)

clean:
	rm -f $(TARGET)

.PHONY: all clean
