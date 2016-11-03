NAME = ft_select
NAMELIB = libft.a
MKDIR = obj
SRC = $(wildcard srcs/*.c)
LIBS = -L./libft/ -lft  
CFLAGS = -Wall -Wextra -Werror

OBJDIR = ./obj/
SRCDIR = ./srcs/
INCDIR = ./includes/

INCLUDES = -I$(INCDIR)

OBJ = $(patsubst srcs/%.c,$(OBJDIR)%.o,$(SRC))


all: $(MKDIR) $(NAMELIB) $(OBJDIR) $(NAME)

$(MKDIR):
	@mkdir $(MKDIR)
$(NAMELIB):
	@(cd libft && $(MAKE))

$(OBJDIR)%.o: $(SRCDIR)%.c
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $^

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBS) -lncurses

clean:
	@(cd libft && $(MAKE) $@)
	@/bin/rm -f $(OBJ)
	@rm -rf obj

fclean: clean
	@(cd libft && $(MAKE) $@)
	/bin/rm -f $(NAME)
	@/bin/rm -rf $(OBJDIR)

re: fclean all

.PHONY: all re clean fclean
