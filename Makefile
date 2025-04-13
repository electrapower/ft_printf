# Name of the executable
NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

# Source files
SRCS = ft_printf.c \
      utils/ft_putchar.c \
      utils/ft_putstr.c \
      utils/ft_putnbr.c \
      utils/ft_puthex.c \
      utils/ft_putptr.c \
      utils/ft_putunsigned.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header file
HEADERS = ft_printf.h

# Default rule to compile the program
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile the source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files
clean:
	rm -f $(OBJS) 

# Fclean rule to remove object files and the executable
fclean: clean
	rm -f $(NAME)

# Rule to clean and recompile everything
re: fclean all

# Phony targets to prevent conflicts with files
.PHONY: all clean fclean re
