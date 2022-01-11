NAME = push_swap
SRC = push_swap.c
OBJ = $(SRC:.c=.o)

NAME_BONUS = checker
SRC_BONUS = checker.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADER = ./includes/push_swap.h
HEADER_BONUS = ./includes/checker.h

CC = gcc -Wall -Wextra -Werror

LIBFT = ./includes/libft/libft.a
GNL = ./includes/gnl/gnl.a

all: ${NAME}

${NAME}: ${LIBFT} ${OBJ} ${HEADER}
	${CC} ${OBJ} ${LIBFT} -o ${NAME}

${LIBFT}:
	make -C ./includes/libft

bonus: ${NAME} ${NAME_BONUS}

${NAME_BONUS}: ${OBJ_BONUS} ${HEADER_BONUS}
	${CC} ${OBJ_BONUS} -o ${NAME_BONUS}

# ${GNL}:
# 	make -C ./includes/gnl


clean:
	rm -f ${OBJ} ${OBJ_BONUS}
	make -C ./includes/libft clean

fclean: clean
	rm -f ${NAME} ${NAME_BONUS} ${LIBFT}

re:	fclean all

.PHONY: all clean fclean re bonus libft
