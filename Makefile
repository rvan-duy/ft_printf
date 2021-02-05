# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-duy <rvan-duy@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/25 22:42:14 by rvan-duy      #+#    #+#                  #
#    Updated: 2021/02/05 15:48:36 by rvan-duy      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
HEADERS	= ft_printf.h
LIBFT	= ./libft/libft.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -I.
SRC_DIR = src
OBJ_DIR = obj

FT_PRINTF =	ft_printf.c \
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
			specifiers/pf_string_expand.c

SRC	= $(addprefix $(SRC_DIR)/, $(FT_PRINTF))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) obj/specifiers
	$(CC) $(FLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)
	@/bin/rm -f .DS_Store

fclean: clean
	make fclean -C ./libft
	/bin/rm -f $(NAME)
	/bin/rm -f a.out
	@/bin/rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: clean fclean re

main: all
	$(CC) $(FLAGS) $(NAME) main.c
	./a.out