NAME = so_long
SRCS_DIR = SRCS
OBJS_DIR = OBJS

LIBFT = make -sC ./libft
LIBFT_PATH = ./SRCS/libft

SRCS = $(wildcard $(SRCS_DIR)/*.c)
# OBJS = $(addprefix $(OBJS_DIR)/,$(notdir $(SRCS:.c=.o)))
OBJS :=$(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -L$(LIBFT_PATH) -lft
INCLUDES = -Imlx_linux 

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	make -sC $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJS_DIR):
	mkdir -p $@

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJS_DIR)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
