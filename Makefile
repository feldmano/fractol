# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: opelman <opelman@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2024/05/14 18:51:24 by opelman       #+#    #+#                  #
#    Updated: 2024/07/30 21:40:43 by opelman       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:= 		fractol

CFLAGS		:=		-Wall -Werror -Wextra -Ofast -flto #-march=native -funroll-loops

HEADERS		:= 		-I./MLX42/include -I./src/libft

MLX42_LIB 	:= 		-lm -ldl -lglfw ./MLX42/build/libmlx42.a

LIBMLX		:= 		./MLX42

LIBFT		:=		./src/libft/libft.a

SRC_DIR		:=		src

SRC_FILES	:=		fractal.c \
					ft_callbacks.c \
					mandelbrot.c \
					julia.c \
					boat.c \

OBJ_DIR		:=		obj

OBJ_FILES	:=		$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

RM			:=		rm -fR

ifdef	DEBUG
	CFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(LIBMLX)
	@cc -o $(NAME) $(CFLAGS) $(OBJ_FILES) $(HEADERS) $(MLX42_LIB) $(LIBFT) && \
	echo "\e[38;5;45mmade $(NAME)\e[0m"

$(LIBFT):
	@$(MAKE) -C ./src/libft -s

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@cc $(CFLAGS) $(HEADERS)  -c $< -o $@

debug:
	make DEBUG=1

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(RM) -f $(OBJ_DIR); \
		$(MAKE) clean -C src/libft -s; \
		echo "\e[31mremoved object files\e[0m"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		$(RM) $(NAME); \
		echo "\e[31mremoved $(NAME)\e[0m"; \
	fi
	@$(MAKE) fclean -C src/libft -s; \

re: fclean $(NAME)

.PHONY: all clean fclean re