NAME	=		libftprintf.a
	
SRC		=		ft_printf.c					\
				ft_printf2.c				\
				ft_add_char.c				\
				ft_itoa_base.c				\
				ft_printf_c.c				\
				ft_printf_d.c				\
				ft_printf_p.c				\
				ft_printf_percent.c			\
				ft_printf_s.c				\
				ft_printf_u.c				\
				ft_printf_x.c				\
				ft_putnbr_ld.c				\
				ft_printf_utils.c			\
				ft_printf_utils2.c			\
				ft_uitoa_base.c				\


OBJ			=	$(SRC:.c=.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
