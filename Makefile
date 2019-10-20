# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seli <seli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 00:20:46 by seli              #+#    #+#              #
#    Updated: 2019/10/20 00:38:41 by seli             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ssl

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_ssl.c
SOURCES := $(SRC:%.c=$(SRC_DIR)/%.c)
OBJECTS := $(SRC:%.c=%.o)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/*.c
	$(CC) $(CLAFGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -I $(INC_DIR) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
