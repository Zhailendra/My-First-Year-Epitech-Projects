##
## EPITECH PROJECT, 2022
## B-PSU-102-LIL-1-1-sokoban-shailendra.blondel
## File description:
## Makefile
##

SOKOBAN	=	src_sokoban

USAGE	=	$(SOKOBAN)/usage

MAP	=	$(SOKOBAN)/map

INIT	=	$(SOKOBAN)/initializer

DISPLAY	=	$(SOKOBAN)/display_game

GET	=	$(SOKOBAN)/get_accurate

TOOLS	=	$(SOKOBAN)/tools

MOVEMENTS = $(SOKOBAN)/movements

SRC	=	$(SOKOBAN)/main.c \
		$(USAGE)/usage.c \
		$(MAP)/get_map.c \
		$(MAP)/check_map.c \
		$(INIT)/initialize_sokoban.c \
		$(DISPLAY)/display_sokoban.c \
		$(DISPLAY)/display_win_lose.c \
		$(GET)/get_lign_and_column.c \
		$(GET)/get_end.c \
		$(GET)/get_movements.c \
		$(GET)/get_obj_nb.c \
		$(TOOLS)/checker.c \
		$(TOOLS)/get_tab.c \
		$(MOVEMENTS)/check_movements.c \

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

NAME	=	my_sokoban

INCLUDE	=	-I include -o

CC	=	gcc -g

CFLAGS	=	-W -Wall -Wextra

LIB	=	-lncurses

all:	$(NAME)

$(NAME):
		make -C ./lib/my/
		$(CC) $(SRC) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB) -L lib/my/ -lmy

clean:
		make clean -C ./lib/my/
		$(RM) $(OBJ)

fclean: clean
		make fclean -C ./lib/my/
		$(RM) $(NAME)

re: fclean all
