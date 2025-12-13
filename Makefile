NAME = push_swap

SRC = src/main.c src/input_validator.c src/ft_atoi.c src/init_stack.c src/utils.c src/utils_stack.c \
		src/operations/swap.c src/operations/rotate.c src/operations/sort_three.c src/operations/push.c \
		src/big_sort.c src/find_targets_in_a.c src/calculate_costs.c src/execute_cheapest_move.c src/ft_split.c
OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = 
INCLUDE = -I include

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re