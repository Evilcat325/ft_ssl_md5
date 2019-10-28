# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seli <seli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 00:20:46 by seli              #+#    #+#              #
#    Updated: 2019/10/28 16:01:50 by seli             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ssl

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_ssl.c md5/ft_md5.c
OBJECTS := $(SOURCES:%.c=$(OBJ_DIR)/%.o)
SOURCES := $(SOURCES:%.c=$(SRC_DIR)/%.o)

.PHONY: all clean fclean re $(OBJ_DIR) $(NAME)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/md5

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
