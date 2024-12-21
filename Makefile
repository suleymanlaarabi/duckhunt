##
## EPITECH PROJECT, 2024
## LibMy
## File description:
## Build and clean the LibMy
##

CFLAGS += -Wextra -Wall
SRC := $(shell find src -name '*.c') main.c
BUILD_DIR = build
OBJS := $(SRC:%.c=$(BUILD_DIR)/%.o)
NAME = my_hunter
DEBUG_NAME = debug
LIB_MY_PATH = ./lib/my/
INCL = -L$(LIB_MY_PATH) -lmy
LIB = $(INCL) -lcsfml-graphics -lcsfml-system -lcsfml-window -lm -lcsfml-audio
INCLUDE_PATH = $(shell find include -type d)
INCLUDE_PATH += $(shell find lib/my/include -type d)
CFLAGS += $(INCLUDE_PATH:%=-I%)

all: libmy $(NAME)

all_debug: libmy

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc -g3 $(CFLAGS) -c $< -o $@

run: all
	@./$(NAME)

$(NAME): $(OBJS)
	@gcc $(CFLAGS) $(OBJS) $(LIB) -o my_hunter

$(DEBUG_NAME): all_debug $(OBJS)
	@gcc -g3 -fsanitize=address $(CFLAGS) $(OBJS) $(LIB) -o debug

libmy:
	@make all -C $(LIB_MY_PATH)

clean_lib:
	@make fclean -C $(LIB_MY_PATH)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean clean_lib
	rm -f $(NAME)

re: fclean all
