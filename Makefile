
SRC_DIR	=	./src

INC	=	./inc

CC	=	gcc

SRC	=	$(SRC_DIR)/main.c	\
		$(SRC_DIR)/particles.c	\
		$(SRC_DIR)/utils.c

OBJS	=	$(SRC:.c=.o)

CFLAGS	=	-I $(INC) -g

LD_FLAGS=	-l c_graph_prog

NAME 	?=	particle

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $@ $(OBJS) $(LD_FLAGS)

%.o:		%.c
		printf "$< ==>> $@\n"
		$(CC) -o $@ -c $< $(CFLAGS) $(LD_FLAGS)

clean:
		rm -rf $(OBJS)

fclean:		clean
		rm -rf $(NAME)
	
re:		fclean all

.PHONY: clean all fclean re
