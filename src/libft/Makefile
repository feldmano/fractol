# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: opelman <opelman@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2024/06/10 18:14:34 by opelman       #+#    #+#                  #
#    Updated: 2024/07/15 16:57:52 by opelman       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

SRC		=	ft_tolower.c ft_toupper.c \
			ft_isascii.c ft_isdigit.c ft_isalnum.c ft_isalpha.c ft_isprint.c \
			ft_calloc.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_memcmp.c ft_memchr.c \
			ft_strlen.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c \
			ft_strdup.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
			ft_striteri.c ft_putendl_fd.c \
			ft_split.c  ft_get_next_line.c ft_printf.c \
			ft_putchr.c ft_putstr.c ft_puti.c ft_putu.c ft_puthex.c ft_puthex_cap.c ft_putptr.c \
			ft_isdigit_str.c ft_isdecimal_str.c ft_atoi.c ft_atof.c \

OBJ_DIR	= obj

OFILES	=	$(SRC:%.c=$(OBJ_DIR)/%.o)

FILE = executable

all: $(NAME)

$(NAME): $(OFILES)
	@ar rcs $(NAME) $(OFILES)

$(OBJ_DIR)/%.o: %.c libft.h 
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

test: all clean
	@$(CC) $(CFLAGS) -o test $(FILE) libft.a

san: all clean
	$(CC) $(CFLAGS) -o test $(FILE) -L. -lft -fsanitize=address -g
	./$(FILE)

.PHONY: all clean fclean re $(FILE)

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(RM) -fR $(OBJ_DIR) \
		echo "\e[31mremoved object files\e[0m"; \
	fi

fclean: clean
	@if [ "$(NAME)" ]; then \
		$(RM) -f $(NAME) \
		echo "\e[31mremoved libft.a \e[0m"; \
	fi

re: fclean all

.PHONY: all clean fclean re 
