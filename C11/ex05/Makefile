CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = do-op
SRCS = $(wildcard *.c)
OBJS = $(SRCS: .c = .o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS): $(SRGC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)
