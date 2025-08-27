# Basic Makefile for a C project

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g

SHARED_ALLOWED_SRCS := libc_builtins.c
SHARED_ALLOWED_OBJS := $(SHARED_ALLOWD_SRCS:.c=.o)
ALLOWED_FCTS_DIR = allowed_functions/

.PHONY: all clean fclean re


g_allowed_% : $(ALLOWED_FCTS_DIR)/%.o $(SHARED_ALLOWED_OBJS)
	ar -rcs $(ALLOWD_FCTS_DIR) $(SHARED_ALLOWED_OBJS) ../$*.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

