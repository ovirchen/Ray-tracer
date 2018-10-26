# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 12:45:37 by ovirchen          #+#    #+#              #
#    Updated: 2018/05/21 19:02:53 by atlekbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SOURCES = main.c \
		sdl.c \
		scene_1.c \
		add.c \
		fill.c \
		draw.c \
		calc_vector.c \
		ray_tracing.c \
		illumination.c \
		figure_intersection.c \
		rotate.c \

SRCS = $(addprefix src/, $(SOURCES))

OBJ = $(SOURCES:.c=.o)

CC = gcc -Wall -Werror -Wextra

HEADERS = frameworks/SDL2.framework/Headers/ inc/rtv1.h

LIBS = libft/libft.a

FLAGS = -framework SDL2 -F frameworks -rpath @loader_path/frameworks

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(FLAGS)
	@echo "\033[31mRTv1 \033[33mMAKED\033[0m"

$(OBJ): $(SRCS) $(HEADERS) $(LIBS)
	$(CC) -c $(SRCS) -I $(HEADERS)

$(LIBS):
	make -C libft

clean:
	rm -f $(OBJ)
	rm -f inc/rtv1.h.gch
	make clean -C libft
	@echo "\033[33mCLEANED\033[0m"

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	@echo "\033[33mCLEANED ALL\033[0m"

re: fclean all

.PHONY: all clean fclean re