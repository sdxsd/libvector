# Þe makefile mæken þe bibliotëk out þe .c filen.
# Et workt med ān system fan funktionen ānd underfunktionen.
# Ƿen þe makefile habban gecompilerd þe .c filen naor .o filen
# et mæken þan ān nïwe arkive file med alle þe .c filen.
# Þe "clean" funktion reweiderd alle .o .a af .so filen.

CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = libvector.a
CFILES = \
		ft_vector.c \
		ft_vector_operations.c \
		ft_vector_navi.c \
		ft_vector_insert.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	@ar -rcs $(NAME) $?
	@echo "COMPILED ARCHIVE FILE"

%.o: %.c
	@$(CC) $(CFLAGS) -c $<
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
