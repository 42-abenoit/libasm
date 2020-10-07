
SRC_DIR = src

SRC_NAME = ft_lstadd_back.c
SRC_NAME += ft_lstadd_front.c
SRC_NAME += ft_lstlast.c
SRC_NAME +=	ft_lstnew.c
SRC_NAME +=	ft_lstsize.c
SRC_NAME += ft_lstdelone.c
SRC_NAME += ft_lstclear.c
SRC_NAME += ft_lstiter.c
SRC_NAME += ft_lstmap.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_NAME))

OBJ_DIR = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

INC = -I inc

NAME	= liblst.a

LIB	= ar rc
CC	= cc
RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra

all:		${NAME}

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	    $(CC) $(INC) $(CFLAGS) $(MLX_DEF) -c $< -o $@

$(OBJ_DIR):
		mkdir -p $@

${NAME}:	${OBJ}
		${LIB} ${NAME} ${OBJ}

clean:
		${RM} -r ${OBJ_DIR}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	clean re fclean
