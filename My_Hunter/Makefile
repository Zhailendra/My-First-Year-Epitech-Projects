##
## EPITECH PROJECT, 2021
## Makefile my_hunter
## File description:
## make my_hunter's window
##

SRC	=	printf/my_printf.c \
		printf/convert_folder/error_display.c \
		printf/convert_folder/directive_functions.c \
		printf/convert_folder/convert_int_functions.c \
		printf/convert_folder/convert_special_functions.c \
		printf/convert_folder/special_case_functions.c \
		printf/convert_folder/new_special_case_functions.c \
		printf/convert_folder/special_case_functions_two.c \
		printf/convert_folder/special_case_functions_three.c \
		printf/convert_folder/my_put_functions.c \
		printf/convert_folder/help_functions.c \
		src_my_hunter/my_hunter.c \
		src_my_hunter/error.c \
		src_my_hunter/manage_animations.c \
		src_my_hunter/sprite_creation.c \
		src_my_hunter/display.c \
		src_my_hunter/my_cursor.c \
		src_my_hunter/get_events.c \
		src_my_hunter/manage_score.c \
		src_my_hunter/manage_lifes.c \
		src_my_hunter/manage_sound.c \
		src_my_hunter/my_tool_functions.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

RM	=	rm -f

CC	=	gcc -g

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system \
	-lcsfml-audio

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
