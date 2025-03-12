# Compiler
CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

# Targets
FILENAME = main.cpp
TARGET = hi_this_is_brain

all: $(TARGET)

# Executable
$(TARGET): $(FILENAME)
	$(CC) $(CFLAGS) -o $(TARGET) $(FILENAME)

clean:
	rm -f $(TARGET)

.PHONY: all clean
