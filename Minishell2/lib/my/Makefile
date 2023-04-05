##
## EPITECH PROJECT, 2022
## My_lib
## File description:
## Makefile
##

PRINTF	=	printf

GET_NEXT_L	=	my_get_next_line

SRC	=	my_atoi.c \
		my_int_len.c \
		my_isdigit.c \
		my_isneg.c \
		my_put_nbr.c \
		my_putchar.c \
		my_putstr.c \
		my_show_word_array.c \
		my_str_isalpha.c \
		my_str_to_word_array.c \
		my_strcat.c \
		my_strcomp.c \
		my_strcpy.c \
		my_strdup.c \
		my_strlen.c \
		my_swap_elements.c \
		my_swap.c \
		$(PRINTF)/my_printf.c \
		$(PRINTF)/convert_folder/error_display.c \
		$(PRINTF)/convert_folder/directive_functions.c \
		$(PRINTF)/convert_folder/convert_int_functions.c \
		$(PRINTF)/convert_folder/convert_special_functions.c \
		$(PRINTF)/convert_folder/special_case_functions.c \
		$(PRINTF)/convert_folder/new_special_case_functions.c \
		$(PRINTF)/convert_folder/special_case_functions_two.c \
		$(PRINTF)/convert_folder/special_case_functions_three.c \
		$(PRINTF)/convert_folder/help_functions.c \
		$(GET_NEXT_L)/my_get_next_line.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CREATE_LIB	=	ar rc $(NAME) $(OBJ)

RM	=	@rm -f

MY_H	=	my.h

MY_PRINTF	=	my_printf.h

MY_GET_NEXT_LINE	=	my_get_nl.h

COPY	=	@cp $(MY_H) ../../include/

COPY_S	=	@cp $(MY_PRINTF) ../../include/

COPY_T	=	@cp $(MY_GET_NEXT_LINE) ../../include/

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CREATE_LIB)
	$(COPY)
	$(COPY_S)
	$(COPY_T)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) ../../include/my.h
	$(RM) ../../include/my_printf.h
	$(RM) ../../include/my_get_nl.h
	$(RM) $(NAME)
