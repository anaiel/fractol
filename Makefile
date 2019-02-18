# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anleclab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 15:21:21 by anleclab          #+#    #+#              #
#    Updated: 2019/02/18 12:15:52 by anleclab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra -Werror 

SRC = main.c \
	  which_fractal.c \
	  end.c \
	  events.c \
	  complex_numbers.c \
	  mandelbrot.c \
	  coordinates.c \
	  draw_fractal.c \
	  new_image.c \
	  color.c

SRCSFD = srcs/
OBJSFD = objs/
OBJS = $(addprefix $(OBJSFD),$(SRC:.c=.o))

HDR = -I./includes
LIBFT_HDR = -I./libft/inc
LIB_BINARY = -L./libft -lft
LIBFT= libft/libft.a

MLX = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all: check_libft $(NAME)

$(NAME): $(OBJSFD) $(OBJS) $(LIBFT)
	@gcc $(FLAGS) $(MLX) $(OBJS) $(LIB_BINARY) -o $@

check_libft:
	@make -C libft

$(OBJSFD):
	@mkdir $@

$(OBJSFD)%.o: $(SRCSFD)%.c
	@gcc $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

clean:
	@rm -rf $(OBJSFD)
	@make -C ./libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all

.PHONY: all check_libft clean fclean re
