##
## EPITECH PROJECT, 2021
## printf lib
## File description:
## Make a library for my_printf
##

SRC	=	src_printf/my_printf.c \
		src_printf/convert_folder/error_display.c \
		src_printf/convert_folder/directive_functions.c \
		src_printf/convert_folder/convert_int_functions.c \
		src_printf/convert_folder/convert_special_functions.c \
		src_printf/convert_folder/special_case_functions.c \
		src_printf/convert_folder/new_special_case_functions.c \
		src_printf/convert_folder/special_case_functions_two.c \
		src_printf/convert_folder/special_case_functions_three.c \
		src_printf/convert_folder/my_put_functions.c \
		src_printf/convert_folder/help_functions.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CREATE_LIBRARY		=	ar rc $(NAME) $(OBJ)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CREATE_LIBRARY)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
