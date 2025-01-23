NAME = so_long
LIBMLX = inc/
LIBFT = inc/Libft/libft.a
HEADERS = -I inc -I $(LIBMLX)/include
LIBS = $(LIBMLX)libmlx42.a -ldl -lglfw -pthread -lm
SRCS =	src/so_long.c src/map.c src/map2.c src/utils.c src/aff.c src/player_move.c
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0 -Wunreachable-code -Ofast
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C inc/Libft

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

clean :
	$(RM) $(OBJS)
	make clean -C inc/Libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C inc/Libft

re : fclean all

.PHONY: all, clean, fclean, re, libmlx

.SILENT:
