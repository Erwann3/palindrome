##
## EPITECH PROJECT, 2023
## B-SYN-200-NAN-2-1-palindrome-erwann.tanguy [WSL: Ubuntu]
## File description:
## Makefile
##

CC = gcc

NAME = palindrome

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -Iinclude

SRCS = src/main.c \
       src/helper.c \
       src/parse.c \
       src/maths.c \
       src/display.c

OBJS = $(SRCS:.c=.o)

SRC_TESTS = tests/tests.c

OBJ_TESTS = $(SRC_TESTS:.c=.o)

TEST_NAME = unit_tests

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

tests_run: CFLAGS += --coverage
tests_run: LDFLAGS += -lcriterion -lgcov
tests_run: $(OBJS) $(OBJ_TESTS)
		$(CC) -o $(TEST_NAME) $(OBJ) $(OBJ_TESTS) $(LDFLAGS)
		./$(TEST_NAME)

.PHONY: all clean fclean re tests_run
