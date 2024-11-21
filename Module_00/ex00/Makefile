
# Compiler
CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

# Targets
FILENAME = megaphone.cpp
TARGET = megaphone

all: $(TARGET)

# Executable
$(TARGET): $(FILENAME)
	$(CC) $(CFLAGS) -o $(TARGET) $(FILENAME)

clean:
	rm -f $(TARGET)

.PHONY: all clean
