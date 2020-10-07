# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenoit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 18:47:34 by abenoit           #+#    #+#              #
#    Updated: 2020/10/07 17:59:20 by abenoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

64_FLAG = -felf64

CASM = nasm

CC = gcc

S_SRC = $(wildcard *.s)

S_OBJ = $(S_SRC:.s=.o)

C_SRC = $(wildcard *.c)

C_OBJ = $(C_SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIB_NAME = libasm.a

INC_LIB = -lc -L ./ -lasm

BIN_NAME = test_libasm

all: $(BIN_NAME)

$(LIB_NAME): $(S_OBJ)
	ar -rc $(LIB_NAME) $(S_OBJ)

$(BIN_NAME): $(C_OBJ) $(LIB_NAME)
	$(CC) $(CFLAGS) $(C_OBJ) -o $(BIN_NAME) $(INC_LIB)

%.o: %.s
	$(CASM) $(64_FLAG) -s $< -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(S_OBJ)
	$(RM) $(C_OBJ)

fclean: clean
	$(RM) $(LIB_NAME)
	$(RM) $(BIN_NAME)

re: fclean all

.PHONY: clean fclean re
