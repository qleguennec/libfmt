NAME = libfmt.a
SRC = echo.c err.c fmt_err.c fmt_fmt.c fmt_int.c fmt_int_sign_32.c fmt_int_sign_64.c fmt_int_unsign.c fmt_print.c fmt_vect.c vfmt.c
OBJ = $(SRC:.c=.o)

CFLAGS += -g -Wall -Wextra -Werror
ARFLAGS = rc

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

clean:
	@rm $(OBJ) 2> /dev/null || true

fclean: clean
	@rm $(NAME) 2> /dev/null || true

re: fclean all
