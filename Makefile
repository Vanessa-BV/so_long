# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vbusekru <vbusekru@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/04/23 14:30:06 by vbusekru      #+#    #+#                  #
#    Updated: 2024/05/14 13:49:41 by vbusekru      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = Libft/libft.a
LIBFTDIR = Libft

MLXLIB = MLX42/build/libmlx42.a

LIBMLX = ./MLX42

CC = cc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

FLAGSMLX = -ldl -pthread -lm -lglfw

RM = rm -f

SOURCE =	main.c \
			create_map_from_input.c \
			map_input_verification.c \
			map_utils.c \
			initialize_game_data.c \
			free_error_utils.c \
			path_check.c \
			game.c \
			textures.c \
			images_to_window.c \
			hooks.c \
			game_collectables.c \

OBJECTS = $(SOURCE:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = objects

all: $(MLXLIB) $(NAME)

$(MLXLIB):
	@cmake $(LIBMLX) -DEBUG=1 -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
	
$(NAME): $(LIBFT) $(MLXLIB) $(OBJS_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) $(FLAGSMLX) $(OBJECTS) $(LIBFT) $(MLXLIB) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:%.c 
	$(CC) $(CFLAGS) -c -o $@ $^

clean: 
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) -rf $(LIBMLX)/build
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re