#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgarcin <mgarcin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 14:58:54 by mgarcin           #+#    #+#              #
#    Updated: 2014/01/24 16:36:33 by mgarcin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			= cc -g3

NAME		= libft.a

SRCDIR		= ./srcs/

SRC			= $(SRCDIR)ft_memset.c			\
			  $(SRCDIR)ft_bzero.c			\
			  $(SRCDIR)ft_memcpy.c			\
			  $(SRCDIR)ft_memccpy.c			\
			  $(SRCDIR)ft_memmove.c			\
			  $(SRCDIR)ft_memchr.c			\
			  $(SRCDIR)ft_memcmp.c			\
			  $(SRCDIR)ft_strlen.c			\
			  $(SRCDIR)ft_strdup.c			\
			  $(SRCDIR)ft_strcpy.c			\
			  $(SRCDIR)ft_strncpy.c			\
			  $(SRCDIR)ft_strcat.c			\
			  $(SRCDIR)ft_strncat.c			\
			  $(SRCDIR)ft_strlcat.c			\
			  $(SRCDIR)ft_strchr.c			\
			  $(SRCDIR)ft_strrchr.c			\
			  $(SRCDIR)ft_strstr.c			\
			  $(SRCDIR)ft_strnstr.c			\
			  $(SRCDIR)ft_strcmp.c			\
			  $(SRCDIR)ft_strncmp.c			\
			  $(SRCDIR)ft_atoi.c			\
			  $(SRCDIR)ft_isalpha.c			\
			  $(SRCDIR)ft_isdigit.c			\
			  $(SRCDIR)ft_isalnum.c			\
			  $(SRCDIR)ft_isascii.c			\
			  $(SRCDIR)ft_isprint.c			\
			  $(SRCDIR)ft_toupper.c			\
			  $(SRCDIR)ft_tolower.c			\
			  $(SRCDIR)ft_memalloc.c		\
			  $(SRCDIR)ft_memdel.c			\
			  $(SRCDIR)ft_strnew.c			\
			  $(SRCDIR)ft_strdel.c			\
			  $(SRCDIR)ft_strclr.c			\
			  $(SRCDIR)ft_striter.c			\
			  $(SRCDIR)ft_striteri.c		\
			  $(SRCDIR)ft_strmap.c			\
			  $(SRCDIR)ft_strmapi.c			\
			  $(SRCDIR)ft_strequ.c			\
			  $(SRCDIR)ft_strnequ.c			\
			  $(SRCDIR)ft_strsub.c			\
			  $(SRCDIR)ft_strjoin.c			\
			  $(SRCDIR)ft_strtrim.c			\
			  $(SRCDIR)ft_strsplit.c		\
			  $(SRCDIR)ft_str_to_wordtab.c	\
			  $(SRCDIR)ft_itoa.c			\
			  $(SRCDIR)ft_putchar.c			\
			  $(SRCDIR)ft_putstr.c			\
			  $(SRCDIR)ft_puterr.c			\
			  $(SRCDIR)ft_putnbr.c			\
			  $(SRCDIR)ft_putchar_fd.c		\
			  $(SRCDIR)ft_putstr_fd.c		\
			  $(SRCDIR)ft_putendl_fd.c		\
			  $(SRCDIR)ft_putnbr_fd.c		\
			  $(SRCDIR)ft_lstnew.c			\
			  $(SRCDIR)ft_lstdelone.c		\
			  $(SRCDIR)ft_lstdel.c			\
			  $(SRCDIR)ft_lstadd.c			\
			  $(SRCDIR)ft_lstiter.c			\
			  $(SRCDIR)memory.c				\
			  $(SRCDIR)x_files.c			\
			  $(SRCDIR)x_ptr.c				\
			  $(SRCDIR)ft_tab_size.c		\
			  $(SRCDIR)ft_free_tab.c		\
			  $(SRCDIR)get_next_line.c		\
			  $(SRCDIR)serialize.c			\
			  $(SRCDIR)serialize_entry.c	\
			  $(SRCDIR)serialize_variable.c	\
			  $(SRCDIR)match.c				\
			  $(SRCDIR)get_content.c

OBJ			= $(SRC:.c=.o)

CFLAGS		= -Wall -Werror -Wextra -ansi -pedantic

INCLUDES	= -I includes/

RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			@echo "\033[1;32m[Linking] \t\033[0m: \033[0;32m" | tr -d '\n'
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
			@echo "\033[0m" | tr -d '\n'

clean:
			@echo "\033[1;33m[Cleaning] \t\033[0m: \033[0;31m" | tr -d '\n'
			$(RM) $(OBJ)
			@echo "\033[0m" | tr -d '\n'

fclean:		clean
			@echo "\033[1;31m[Fcleaning] \t\033[0m: \033[0;31m" | tr -d '\n'
			$(RM) save_libft.tar.gz
			$(RM) $(NAME)
			@echo "\033[0m" | tr -d '\n'

re:			fclean all

%.o:		%.c
			@echo "\033[1;36m[Compiling] \t\033[0m: \033[1;37m" | tr -d '\n'
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
			@echo "\033[0m" | tr -d '\n'

.PHONY:		all clean re fclean
