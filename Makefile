# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seli <seli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 00:20:46 by seli              #+#    #+#              #
#    Updated: 2019/10/29 17:41:05 by seli             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ssl

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
SUB_DIR = parse format md5 sha message_digest
LIBFT_HEADER = libft/includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_ssl.c \
					md5/ft_md5.c \
					sha/ft_sha.c \
					format/ft_ssl_print.c \
					parse/ft_ssl_flag.c \
					parse/ft_ssl_parser.c \
					message_digest/ft_message_digest.c
OBJECTS := $(SOURCES:%.c=$(OBJ_DIR)/%.o)
SOURCES := $(SOURCES:%.c=$(SRC_DIR)/%.o)
SUB_DIR := $(SUB_DIR:%=$(OBJ_DIR)/%)

.PHONY: all clean fclean re libft $(OBJ_DIR) $(NAME)

all: $(NAME)

libft:
	make -C libft

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(SUB_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_HEADER) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_HEADER) -lft -o $(NAME) $(OBJECTS)

clean:
	make clean -C libft
	rm -f $(OBJECTS)

fclean: clean
	make clean -C libft
	rm -fd $(SUB_DIR)
	rm -d $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all
