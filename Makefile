BUILD_PATH ?= ./build
LIB_NAME = $(BUILD_PATH)/libgnl.a

CC			= cc
INCLUDE		= include
CFLAGS		= -Wall -Wextra -Werror -I$(INCLUDE)

SRCS		= src/get_next_line.c \
				src/get_next_line_utils.c
OBJS		= $(SRCS:src/%.c=$(BUILD_PATH)/obj/%.o)
HEADER_FILES	= include/libgnl.h

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS) $(HEADER_FILES)
	ar rcs $(LIB_NAME) $(OBJS)

$(BUILD_PATH)/obj/%.o: src/%.c $(HEADER_FILES)
	@mkdir -p $(BUILD_PATH)/obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_PATH)/obj

fclean: clean
	@rm -rf $(BUILD_PATH)

re: fclean all

.PHONY: all clean fclean re
