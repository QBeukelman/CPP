# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: quentinbeukelman <quentinbeukelman@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/17 23:19:04 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/03/17 23:33:21 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = g++

CFLAGS = -Wall -Werror -Wextra -std=c++98

TARGET			= zombie
UTILS			= ../utils/utils.cpp

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp testZombie.cpp $(UTILS)
OBJS = $(SRCS:.cpp=.o)

# Targets
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp Zombie.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) test_runner
	rm -rf $(GTEST_BUILD_DIR)

.PHONY: all clean test
