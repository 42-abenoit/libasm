# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenoit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 18:47:34 by abenoit           #+#    #+#              #
#    Updated: 2020/11/01 15:20:23 by abenoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS = $(shell uname -s)

ifeq ($(OS),Darwin)
	S_SRC_DIR += src_macos
	64_FLAG = -fmacho64
else
	S_SRC_DIR += src_linux
	64_FLAG = -felf64
endif

AR = ar -rc

CASM = nasm

CC = clang

OBJ_DIR = obj

S_SRC_NAME += ft_atoi_base_bonus.s
S_SRC_NAME += ft_list_push_front_bonus.s
S_SRC_NAME += ft_read.s
S_SRC_NAME += ft_write.s
S_SRC_NAME += ft_strcpy.s
S_SRC_NAME += ft_strcmp.s
S_SRC_NAME += ft_strdup.s
S_SRC_NAME += ft_strlen.s

S_SRC = $(addprefix $(S_SRC_DIR)/,$(S_SRC_NAME))

S_OBJ_NAME = $(S_SRC_NAME:.s=.o)

S_OBJ = $(addprefix $(OBJ_DIR)/,$(S_OBJ_NAME))

C_SRC_DIR = tester

C_SRC_NAME += full_test.c
C_SRC_NAME += main.c
C_SRC_NAME += rec_gnl.c
C_SRC_NAME += utils.c

C_SRC = $(addprefix $(C_SRC_DIR)/,$(C_SRC_NAME))

C_OBJ_NAME = $(C_SRC_NAME:.c=.o)

C_OBJ = $(addprefix $(OBJ_DIR)/,$(C_OBJ_NAME))

CFLAGS = -Wall -Werror -Wextra

LIB_NAME = libasm.a

INC = -I inc

INC_LIB = -lc -L. -lasm

BIN_NAME = test_libasm

all: $(BIN_NAME)

$(LIB_NAME): $(S_OBJ)
	$(AR) $(LIB_NAME) $(S_OBJ)

$(BIN_NAME): $(C_OBJ) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $(C_OBJ) $(INC) $(INC_LIB)

$(OBJ_DIR)/%.o: $(S_SRC_DIR)/%.s | $(OBJ_DIR)
	$(CASM) $(64_FLAG) -s $< -o $@

$(OBJ_DIR)/%.o: $(C_SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(INC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) $(S_OBJ)
	$(RM) $(C_OBJ)

fclean: clean
	$(RM) $(LIB_NAME)
	$(RM) $(BIN_NAME)

re: fclean all

.PHONY: clean fclean re
