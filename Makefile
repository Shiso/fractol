# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/02 15:57:35 by mgarcin           #+#    #+#              #
#    Updated: 2015/03/05 16:52:29 by mgarcin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRLIB	=	libft/
LIBFT	=	libft/libft.a
FLAGS	=	-Wall -Werror -Wextra
NAME	=	Fractol
SRCS	=	src/main.c \
			src/utils.c
OBJS	=	$(SRCS:.c=.o)
MLX		=	-Llibft -lft -g -L/usr/X11/lib -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)


$(NAME): $(LIBFT) $(OBJS)
	gcc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLX)

$(LIBFT):
	@(cd $(DIRLIB) && $(MAKE))

clean:
	@(cd $(DIRLIB) && $(MAKE) $@)
	@(rm -rf $(OBJS))

fclean: clean
	@(cd $(DIRLIB) && $(MAKE) $@)
	@(rm -rf $(NAME))

re: fclean all

.PHONY : all clean fclean re
