
# Compiler
CC = g++
GTEST_DIR = extern/googletest
GTEST_LIB = $(GTEST_DIR)/build/lib/libgtest.a
GTEST_INCLUDE = $(GTEST_DIR)/googletest/include

CFLAGS = -Wall -Werror -Wextra -std=c++98

TARGET = zombie
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp testZombie.cpp
OBJS = $(SRCS:.cpp=.o)


# Targets
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

test: $(OBJS) $(TEST_OBJS) $(GTEST_LIB)
	$(CC) $(CFLAGS) -o test_runner $(OBJS) $(TEST_OBJS) $(GTEST_LIB) -pthread

%.o: %.cpp Zombie.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) test_runner
	rm -rf $(GTEST_BUILD_DIR)

.PHONY: all clean test
