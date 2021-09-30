NAME = libftprintf.a

INC_DIR = .

SRCS = ft_itoa_base.c ft_printf.c ft_printf_addfunc.c ft_printf_p_6.c ft_printf_search_type_3.c ft_printf_flag_type_1.c ft_printf_width_prec_2.c\
		ft_printf_libft.c ft_printf_print_num_5.c ft_printf_print_str_4.c\

OBJS	   = ${SRCS:.c=.o}

DEPS	   = ft_printf.h

CFLAGS	   = -Wall -Wextra -Werror -I${INC_DIR}

AR		   = ar rc

.c.o :		${DEPS}
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

bonus:		${BONUS_OBJS}
			${AR} ${NAME} ${BONUS_OBJS}

clean:
			rm -f ${OBJS} ${BONUS_OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
