# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 11:37:19 by hmeftah           #+#    #+#              #
#    Updated: 2023/05/26 12:57:42 by hmeftah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_malloc.a

FLAGS = -Wall -Werror -Wextra

CC = cc

SOURCES = $(addprefix ./, ft_malloc.c misc_functions.c misc_functions2.c)

INCLUDE = ft_malloc.h

all: $(NAME) $(SOURCES)

$(NAME): $(SOURCES:.c=.o) $(INCLUDE)
	ar -r $(NAME) $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDE) -c $<

clean:
	rm -rf $(SOURCES:.c=.o)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re