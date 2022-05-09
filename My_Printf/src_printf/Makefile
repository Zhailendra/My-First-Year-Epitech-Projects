##
## EPITECH PROJECT, 2021
## makefile -> printf
## File description:
## Make printf function
##

SRC	=	my_printf.c \
		convert_folder/directive_functions.c \
		convert_folder/error_display.c \
		convert_folder/convert_int_functions.c \
		convert_folder/convert_special_functions.c \
		convert_folder/special_case_functions.c \
		convert_folder/new_special_case_functions.c \
		convert_folder/special_case_functions_two.c \
		convert_folder/special_case_functions_three.c \
		convert_folder/help_functions.c \
		convert_folder/my_put_functions.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

NAME	=	printf

CFLAGS	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
