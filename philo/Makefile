# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 18:59:02 by adbaich           #+#    #+#              #
#    Updated: 2022/05/16 20:57:22 by adbaich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = ft_atoi.c \
	msg_and_usleep.c \
	philosophers.c \
	actions.c \
	check_args.c \
	join_threads.c \
	four_or_five_args.c \

OBJ := $(patsubst %.c,%.o, ${SRC})
NAME = philosopher

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
