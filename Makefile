NAME = lem-in
# CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR = ft_printf/
LIBFT = $(LIBFT_DIR)libftprintf.a
LIBFT_HEADERS = $(LIBFT_DIR)includes/
LIB_FLAG := -L./$(LIBFT_DIR) -lftprintf

HEADERS_DIR = includes/
HEADERS_LST = lemin.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LST))
INCLUDES := -I $(HEADERS_DIR) -I $(LIBFT_HEADERS)

SRC_DIR = srcs/
SRC_DIR_PARSE = parse/
SRC_DIR_LOGIC = logic/
SRC_DIR_OUTPUT = output/

SRC_MAIN = lemin.c
SRC_PARSE_FILES =
SRC_LOGIC_FILES = bfs.c dinic.c find_path.c set_path.c add_path.c new_path.c reverse_paths.c
SRC_OUTPUT_FILES = send_aints.c set_prior.c move_ants.c

SRC_PARSE = $(addprefix $(SRC_DIR_PARSE), $(SRC_PARSE_FILES))
SRC_LOGIC = $(addprefix $(SRC_DIR_LOGIC), $(SRC_LOGIC_FILES))
SRC_OUTPUT = $(addprefix $(SRC_DIR_OUTPUT), $(SRC_OUTPUT_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_LST))

SRCS_LST = $(SRC_MAIN) $(SRC_PARSE) $(SRC_LOGIC) $(SRC_OUTPUT)

OBJ_DIR = objects/
OBJ_DIRS = $(addprefix $(OBJ_DIR), $(SRC_DIR_PARSE)) $(addprefix $(OBJ_DIR), $(SRC_DIR_LOGIC)) $(addprefix $(OBJ_DIR), $(SRC_DIR_OUTPUT))
OBJ_LST = $(patsubst %.c, %.o, $(SRCS_LST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LST))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(INCLUDES) $(LIB_FLAG) -o $(NAME)

$(LIBFT):
	make -sC $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(OBJ_DIRS)

objects/%.o : srcs/%.c $(HEADERS)
	gcc $(CFLAGS) -c $(INCLUDES) $< -o $@

clean:
	make -sC $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -sC $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re