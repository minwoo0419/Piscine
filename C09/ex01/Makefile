CC = gcc
CFLAGS	= -Wall -Wextra -Werror
TARGET	= libft.a
AR = ar crs
SRC_DIR = srcs
HD_DIR = includes
SRCS	= $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_swap.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strcmp.c
OBJS	= $(SRCS:.c=.o)

all :	$(TARGET)

$(TARGET) : $(OBJS)
	$(AR) $@ $^

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@ -I/$(HD_DIR)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
