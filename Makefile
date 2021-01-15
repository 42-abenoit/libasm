# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenoit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 18:47:34 by abenoit           #+#    #+#              #
#    Updated: 2021/01/15 15:22:00 by abenoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS = $(shell uname -s)

ifeq ($(OS),Darwin)
	OS_DEF = -D os_mac
	64_FLAG = -fmacho64
else
	OS_DEF = -D os_linux
	64_FLAG = -felf64
endif
CASM = nasm

CC = clang

S_SRC = $(wildcard *.s)

S_OBJ = $(S_SRC:.s=.o)

C_SRC = $(wildcard *.c)

C_OBJ = $(C_SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

ifeq ($(d), 1)
	CFLAGS += -g -fsanitize=address
endif

LIB_NAME = libasm.a

LIB_LST_DIR = liblst/

INC = -I $(LIB_LST_DIR)inc

INC_LIB += -lc -L ./ -lasm
INC_LIB += -L$(LIB_LST_DIR) -llst

BIN_NAME = test_libasm

all: $(BIN_NAME)

$(LIB_NAME): $(S_OBJ)
	ar -rc $(LIB_NAME) $(S_OBJ)

$(BIN_NAME): $(C_OBJ) $(LIB_NAME) LIB_LST
	$(CC) $(CFLAGS) $(C_OBJ) -o $(BIN_NAME) $(INC) $(INC_LIB)

%.o: %.s
	$(CASM) $(64_FLAG) -s $< -o $@ $(OS_DEF)

%.o: %.c
	$(CC) $(INC) -c $< -o $@

LIB_LST:
		make -C $(LIB_LST_DIR)

clean:
	$(RM) $(S_OBJ)
	$(RM) $(C_OBJ)

fclean: clean
	$(RM) $(LIB_NAME)
	$(RM) $(BIN_NAME)
	make -C $(LIB_LST_DIR) fclean

re: fclean all

.PHONY: clean fclean re

