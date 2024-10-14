# Set final target name
NAME	= libft.a

# Compiler settings
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# Set colors variables
RESET	= \033[0;39m
RED		= \033[0;91m
GREEN	= \033[0;92m
MAGENTA	= \033[0;95m
YELLOW	= \033[0;93m

# Set all rule in first
all: $(NAME)

# Include include.mk for load (OBJECTS, SOURCES) variables
# and load rul for make object files from source files
include include.mk

# libft.a rule for make target
$(NAME): $(OBJECTS)
	@test -f $(NAME) \
		&& echo "$(MAGENTA)Update archive $(NAME) $(RESET)" \
		|| echo "$(MAGENTA)Create archive $(NAME) $(RESET)"
	@ar rcs $(NAME) $?

# Clean all object files only
clean:
	@rm -f $(OBJECTS) \
		&& echo "$(YELLOW)LIBFTPRINTF: remove all object files$(RESET)"\
		|| echo "$(RED)LIBFTPRINTF: Can't remove object files$(RESET)"

# Clean all object files and archives file
fclean: clean
	@rm -f $(NAME) \
		&& echo "$(YELLOW)LIBFT: Remove $(NAME)$(RESET)"\
		|| echo "$(RED)LIBFT: Can't remove $(NAME)$(RESET)"


# Clean all object files and archives files and build again
re: fclean all

.PHONY: all clean fclean re