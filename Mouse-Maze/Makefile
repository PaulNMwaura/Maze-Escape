SHELL = cmd.exe
TARGET = my_mouse.exe
SRCS = main.c find_shortest_path.c check_maze.c validate.c solve_mark.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if exist *.o del /Q *.o

fclean: clean
	@if exist $(TARGET) del /Q $(TARGET)

re: fclean all