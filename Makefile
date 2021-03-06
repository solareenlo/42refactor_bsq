# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 13:12:23 by louisnop          #+#    #+#              #
#    Updated: 2021/10/07 21:38:24 by tayamamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
TARGET  = bsq
SRC = main.c ft_puts.c ft_utility.c ft_str.c ft_split.c ft_atoi.c ft_parse_map_info.c ft_validate_map.c ft_validate_map_info.c ft_make_square.c ft_help_make_square.c ft_free.c ft_put_map.c
OBJ = main.o ft_puts.o ft_utility.o ft_str.o ft_split.o ft_atoi.o ft_parse_map_info.o ft_validate_map.o ft_validate_map_info.o ft_make_square.o ft_help_make_square.o ft_free.o ft_put_map.o
SRC_DIR = ./
OBJ_DIR = obj
SRCS    = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS    = $(addprefix $(OBJ_DIR)/, $(OBJ))

.PHONY: all
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: leak
leak: CFLAGS += -g -fsanitize=leak
leak: re

.PHONY: address
address: CFLAGS += -g -fsanitize=address
address: re

.PHONY: val
val: re
val:
	valgrind --leak-check=full --show-leak-kinds=all ./bsq example_file

.PHONY: clean
clean:
	-rm -fr $(OBJ_DIR) *.dSYM

.PHONY: fclean
fclean:
	-rm -fr $(TARGET) $(OBJ_DIR) *.dSMY

.PHONY: re
re: fclean all
