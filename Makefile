# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seli <seli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 00:20:46 by seli              #+#    #+#              #
#    Updated: 2019/10/20 00:58:38 by seli             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ssl

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_ssl.c
OBJECTS := $(SOURCES:%.c=$(OBJ_DIR)/%.o)
SOURCES := $(SOURCES:%.c=$(SRC_DIR)/%.c)

.PHONY: all clean fclean rerm

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -d $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all
