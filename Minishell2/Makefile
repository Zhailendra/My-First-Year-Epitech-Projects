##
## EPITECH PROJECT, 2022
## B-PSU-101-LIL-1-1-minishell1-shailendra.blondel
## File description:
## Makefile
##

PRINT = printf

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

MINISHELL	=	src_shell

BUILTINS	=	/builtins

TOOLS	=	/tools

SRC	=	$(MINISHELL)/main.c \
		$(MINISHELL)/initializer/initialize.c \
		$(MINISHELL)/initializer/init.c \
		$(MINISHELL)/initializer/redirections.c \
		$(MINISHELL)/shell/shell.c \
		$(MINISHELL)/shell/get_pipe.c \
		$(MINISHELL)$(TOOLS)/my_tablen.c \
		$(MINISHELL)$(TOOLS)/signal.c \
		$(MINISHELL)$(TOOLS)/write_error.c \
		$(MINISHELL)$(TOOLS)/my_str_isupper.c \
		$(MINISHELL)$(TOOLS)/error_handle.c \
		$(MINISHELL)$(TOOLS)/str_check.c \
		$(MINISHELL)$(TOOLS)/my_getnbr.c \
		$(MINISHELL)$(TOOLS)/check_if_digit.c \
		$(MINISHELL)$(TOOLS)/free.c \
		$(MINISHELL)$(TOOLS)/shell_checker.c \
		$(MINISHELL)/parsing/parse_commands.c \
		$(MINISHELL)/parsing/parsing.c \
		$(MINISHELL)/parsing/placement.c \
		$(MINISHELL)$(BUILTINS)/get_builtins.c \
		$(MINISHELL)$(BUILTINS)/my_cd.c \
		$(MINISHELL)$(BUILTINS)/change_dir.c \
		$(MINISHELL)$(BUILTINS)/cd_directives.c \
		$(MINISHELL)$(BUILTINS)/cd_path.c \
		$(MINISHELL)$(BUILTINS)/my_env.c \
		$(MINISHELL)$(BUILTINS)/my_setenv.c \
		$(MINISHELL)$(BUILTINS)/setenv_tool.c \
		$(MINISHELL)$(BUILTINS)/my_unsetenv.c \
		$(MINISHELL)$(BUILTINS)/my_exit.c \
		$(MINISHELL)/commands/get_execve.c \
		$(MINISHELL)/commands/get_exe.c \
		$(MINISHELL)/commands/check_execve.c \
		$(MINISHELL)/commands/get_my_path.c \

OBJ	=	$(SRC:.c=.o)

CC	=	@gcc -g

BINARY	=	mysh

LIB	=	-L ./lib/my/

CFLAGS	=	-I include -Wall -Wextra

LIBC	=	-lmy

all: $(BINARY)

$(BINARY) : build_lib $(OBJ)
	@$(PRINT) "$(YELLOW)Compiling $(BINARY)...$(RESET)\n"
	@$(CC) -o $(BINARY) $(OBJ) $(CFLAGS) $(LIB) $(LIBC) & \
	while [ -e /proc/$sPID ]; do \
	  $(PRINT) -n "$(BLUE)#"; \
	  sleep 0.2; \
	done; \
	if [ $$? -eq 0 ]; then \
	  $(PRINT) "$(GREEN)$(BINARY) compiled successfully!$(RESET)\n"; \
	else \
	  $(PRINT) "$(RED)Compilation failed!$(RESET)\n"; \
	fi

build_lib:
	@make -s all -C ./lib/my/

clean:
	@$(PRINT) "$(YELLOW)Cleaning up...$(RESET)\n"
	@$(RM) $(OBJ)
	@$(RM) vgcore.*
	@$(PRINT) "$(GREEN)Cleanup complete!$(RESET)\n"

fclean: clean
	@$(PRINT) "$(YELLOW)Removing $(BINARY)...$(RESET)\n"
	@$(RM) $(BINARY)
	@$(PRINT) "$(GREEN)$(BINARY) removed!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
