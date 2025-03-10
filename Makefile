NAME		= fdf

INCDIR		= include
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft
FT_PRINTF_DIR = ft_printf
GET_NEXT_LINE_DIR = get_next_line
MLX_DIR = minilibx

LIBFT		= $(LIBFT_DIR)/libft.a
FT_PRINTF   = $(FT_PRINTF_DIR)/libftprintf.a
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a
MLX	= $(MLX_DIR)/libmlx_Linux.a


CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INCDIR) -g3
RM			= rm -f
AR			= ar rcs

SRC			= fdf.c \
			  list.c \
			  readfile.c \
			  check.c \
			  control.c \
			  control_utils.c \
			  rotate.c \
			  drawline.c \
			  color.c \
			  text_display.c \
			  readfile_utils.c \
			  utils.c \
			  free.c \

OBJ 		= $(SRC:%.c=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(MLX) \
	-lX11 -lXext -lm -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(GET_NEXT_LINE):
	$(MAKE) -C $(GET_NEXT_LINE_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

all: $(NAME)

clean:
	$(RM) -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
