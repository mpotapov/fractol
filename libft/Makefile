#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/29 18:32:21 by mpotapov          #+#    #+#              #
#    Updated: 2017/01/04 19:23:11 by mpotapov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = *.c

OBJ = $(SRC:.c=.o)

F = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(F) $(SRC) -I Includes
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME) 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all