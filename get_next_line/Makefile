NAME		= get_next_line.a
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= ../libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDE		= include
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INCLUDE)
RM			= rm -f
AR			= ar rcs

SRC			= get_next_line.c

OBJ 		= $(SRC:%.c=$(OBJ_DIR)/%.o)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(RM) -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re