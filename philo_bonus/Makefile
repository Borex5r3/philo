# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 00:37:49 by adbaich           #+#    #+#              #
#    Updated: 2022/05/22 00:44:34 by adbaich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


BNS = ft_atoi_bonus.c \
	msg_and_usleep_bonus.c \
	philosophers_bonus.c \
	actions_bonus.c \
	check_args_bonus.c \
	four_or_five_args_bonus.c \
	end_processes_bonus.c \
	the_thread_bonus.c \

OBJ_BNS := $(patsubst %.c,%.o, ${BNS})
NAME = philosopher_bonus

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

bonus: ${NAME}

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ_BNS}
	${CC} ${CFLAGS} ${OBJ_BNS} -o ${NAME}

clean:
	${RM} ${OBJ_BNS}

fclean: clean
	${RM} ${NAME}

re: fclean all