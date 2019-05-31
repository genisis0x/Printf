CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBDIR = ./libft/
SRC = ft_printf.c parser.c cov_chr_str_ptr_mod.c cov_float.c cov_int.c cov_uint.c \
	  utils.c

LIBFILES = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_striter.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_iswhitespace.c \
		ft_strwhitespace.c \
		ft_otherwhitespace.c \
		ft_strtrim.c \
		ft_count.c \
		ft_strsplit.c \
		ft_intlen.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_ulltoa.c \
		ft_lltoa.c

LIBSRC = $(patsubst %, $(LIBDIR)%, $(LIBFILES))
OBJ = $(SRC:.c=.o)
LIBOBJ = $(LIBSRC:.c=.o)
INC = ft_printf.h libft/libft.h

.PHONY: all clean fclean re lib

all: $(NAME)

$(NAME): lib
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ) $(LIBOBJ)
	ranlib $(NAME)

lib:
	$(MAKE) -C ./libft/

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./libft/ clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C ./libft/ fclean

re: fclean all
