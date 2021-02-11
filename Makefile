# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-duy <rvan-duy@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/25 22:42:14 by rvan-duy      #+#    #+#                  #
#    Updated: 2021/02/11 15:14:06 by rvan-duy      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -I $(HEADER)
HEADER 	= include
PRINTF	= ft_printf.c \
			pf_format_specifier_handler.c \
			pf_string_create.c \
			pf_utils_1.c \
			pf_utils_2.c \
			specifiers/pf_string_c_create.c \
			specifiers/pf_string_d_create.c \
			specifiers/pf_string_p_create.c \
			specifiers/pf_string_s_create.c \
			specifiers/pf_string_u_create.c \
			specifiers/pf_string_x_create.c \
			specifiers/pf_string_percentage_create.c \
			specifiers/pf_string_expand.c

LIBFT	= ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isdigit.c \
			ft_itoa.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strndup.c		

SRC_DIRS = \
	$(addprefix libft/, $(LIBFT)) \
	$(addprefix printf/, $(PRINTF))

OBJ_DIRS = \
	obj \
	obj/libft \
	obj/printf \
	obj/printf/specifiers

all: $(NAME)

SRC	= $(addprefix src/, $(SRC_DIRS))
OBJ = $(SRC:src/%.c=obj/%.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIRS)
	$(CC) $(FLAGS) -c $< -o $@

.PHONY:	clean fclean re

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f .DS_Store
	@/bin/rm -f a.out

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *.a
	@/bin/rm -rf $(OBJ_DIRS)

re: fclean all

main: all
	$(CC) $(FLAGS) $(UNUSED) $(NAME) main.c utils/*.c
	./a.out

test: main