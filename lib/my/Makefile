##
## EPITECH PROJECT, 2019
## lib
## File description:
## make the lib
##

SRC	=	array/array_dup.c	\
		array/edit_array.c	\
		array/find_arr_line.c	\
		array/free_array.c	\
		array/str_to_arr.c	\
		array/my_array_size.c	\
		compare/is_int.c	\
		compare/my_strcmp.c	\
		compare/my_strncmp.c	\
		convert/my_atoi.c	\
		file/gnl.c		\
		math/my_pow.c		\
		str/my_strcat.c		\
		str/my_strdup.c		\
		str/my_strdup_xy.c	\
		str/my_strlen.c		\
		str/my_revstr.c		\
		str/my_strdupline.c	\
		str/my_strcpy.c		\
		str/my_str_isnum.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I ../../include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

