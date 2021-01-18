# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenoit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 18:47:34 by abenoit           #+#    #+#              #
#    Updated: 2021/01/18 13:18:55 by abenoit          ###   ########.fr        #
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

S_SRC += ft_strlen.s
S_SRC += ft_strcpy.s
S_SRC += ft_strcmp.s
S_SRC += ft_write.s
S_SRC += ft_read.s
S_SRC += ft_strdup.s

S_SRC_BONUS += ft_atoi_base_bonus.s
S_SRC_BONUS += ft_list_push_front_bonus.s
S_SRC_BONUS += ft_list_size_bonus.s
S_SRC_BONUS += ft_list_sort_bonus.s
S_SRC_BONUS += ft_list_remove_if_bonus.s

S_OBJ = $(S_SRC:.s=.o)
S_OBJ_BONUS = $(S_SRC_BONUS:.s=.o)

C_SRC += main.c
C_SRC += utils.c
C_SRC += rec_gnl.c
C_SRC += full_test.c

C_SRC_BONUS += list_tests.c
C_SRC_BONUS += list_utils.c

C_OBJ = $(C_SRC:.c=.o)
C_OBJ_BONUS = $(C_SRC_BONUS:.c=.o)

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

RM = rm -f

all: $(BIN_NAME)

bonus: BONUS_DEF = -D bonus
bonus: all

#ifeq ($(bonus),)
$(LIB_NAME): $(S_OBJ)
	ar -rc $(LIB_NAME) $(S_OBJ)

$(BIN_NAME): $(C_OBJ) $(LIB_NAME) LIB_LST
	$(CC) $(CFLAGS) $(C_OBJ) -o $(BIN_NAME) $(INC) $(INC_LIB)

%.o: %.s
	$(CASM) $(64_FLAG) -s $< -o $@ $(OS_DEF)

%.o: %.c
	$(CC) $(INC) $(BONUS_DEF) -c $< -o $@

LIB_LST:
		make -C $(LIB_LST_DIR)

clean:
	$(RM) $(S_OBJ)
	$(RM) $(S_OBJ_BONUS)
	$(RM) $(C_OBJ)
	$(RM) $(C_OBJ_BONUS)

fclean: clean
	$(RM) $(LIB_NAME)
	$(RM) $(BIN_NAME)
	make -C $(LIB_LST_DIR) fclean

re: fclean all

.PHONY: clean fclean re

