#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/28 17:16:30 by mpotapov          #+#    #+#              #
#    Updated: 2017/10/27 12:51:58 by mpotapov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

OBJ = main.o key_events.o mandelbrot.o julia.o burning_ship.o menu.o fractals.o pifagor.o brasenhamline.o sqare.o

FLAGS = -Wall -Wextra -Werror -O3 -lmlx -framework OpenGL -framework AppKit

all: $(OBJ) $(NAME)

$(NAME):
	@make -C ./libft
	@gcc $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)
	@echo "\n\033[22;32mCompiled\033[0m\n"
%.o: %.c
	@gcc -o $@ -c $< -I . -I ./libft
clean:
	@make clean -C ./libft
	@rm -rf $(OBJ)
	@echo "\n\033[22;32mObjects deleted\033[0m\n"
fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft
	@echo "\n\033[22;32mExecutable deleted\033[0m\n"
re: fclean all