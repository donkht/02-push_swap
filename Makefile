NAME		=			push_swap
SRC			=			push_swap.c \
						push_swap_utils.c \
						operations1.c \
						operations2.c \
						operations3.c \
						sort.c

OBJ			=			$(SRC:.c=.o)

NAME_BONUS	=			checker
SRC_BONUS	=			checker.c \
						checker_2utils.c \
						checker_3finish.c \
						checker_gnl.c \
						checker_gnl_utils.c \
						checker_op1.c \
						checker_op2.c \
						checker_op3.c

OBJ_BONUS	=			$(SRC_BONUS:.c=.o)

HEADER		=			./includes/push_swap.h
HEADER_BONUS =			./includes/checker.h

CC			=			gcc -Wall -Wextra -Werror

LIBFT		=			./includes/libft/libft.a
# GNL			=			./includes/gnl/gnl.a

all: ${NAME}

${NAME}: ${LIBFT} ${OBJ} ${HEADER}
	${CC} ${OBJ} ${LIBFT} -o ${NAME}

${LIBFT}:
	make -C ./includes/libft

bonus: ${NAME_BONUS}

${NAME_BONUS}:  ${LIBFT} ${OBJ_BONUS} ${HEADER_BONUS}
	${CC} ${OBJ_BONUS} ${LIBFT} -o ${NAME_BONUS}

# ${GNL}:
#	make -C ./includes/gnl

clean:
	rm -f ${OBJ} ${OBJ_BONUS}
	make -C ./includes/libft clean
#	make -C ./includes/gnl clean	

fclean: clean
	rm -f ${NAME} ${NAME_BONUS} ${LIBFT}

re:	fclean all

.PHONY: all clean fclean re bonus libft gnl
