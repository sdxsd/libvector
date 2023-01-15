CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = libvector.a
CFILES = \
		src/ft_vector.c \
		src/ft_vector_operations.c \
		src/ft_vector_navi.c \
		src/ft_vector_insert.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	@ar -rcs $(NAME) $?
	@echo "COMPILED ARCHIVE FILE"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo COMPILED: $<

re: fclean all

fclean: clean
	@rm -f $(NAME)
	@echo "DEEP CLEANING"

clean:
	@rm -f $(OFILES)
	@rm -f $(B_OFILES)
	@rm -f a.out
	@echo "CLEANED UP"

so: $(NAME)
	$(CC) $(CFLAGS) $(OFILES) -o libft.so
