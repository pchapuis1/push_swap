SRCS		=	main.c \
				ft_nb_number.c \
				ft_split.c \
				ft_atoi.c \
				ft_place.c \
				ft_push.c \
				ft_reverse.c \
				ft_rotate.c \
				ft_swap.c \
				ft_check_output.c \
				ft_sort.c \
				ft_median.c \
				ft_sort_3.c \
				ft_find_extrem.c \
				ft_send_b.c \
				ft_check.c

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

CC			= cc

RM 			= rm -f

CFLAGS		= -Wall -Wextra -Werror

HEADERS		= push_swap.h

%.o:		%.c ${HEADERS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS} ${HEADERS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

