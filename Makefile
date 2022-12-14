SRCS	= init.c main.c parsing.c split.c clear.c display.c flechies.c random.c searching.c verif.c sentence.c

DIR_SRC	= ./

OBJ	= ${SRCS:.c=.o}

DIR_OBJ = ./objs/

OBJS=$(addprefix $(DIR_OBJ), $(OBJ))

NAME	= dictionary

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -g 

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:	${NAME}

clean:
		rm -f ${OBJS}

fclean:	
		rm -f ${NAME}
		rm -f ${OBJS}

re:		fclean
		make all

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
				$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
