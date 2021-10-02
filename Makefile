NAME 		=	pipex

SRCS  		=	main_part/main.c \
				main_part/utils.c \
				main_part/main_process.c \
				libft_lite/ft_putchar_fd.c \
				libft_lite/ft_putstr_fd.c \
				libft_lite/ft_strnstr.c \
				libft_lite/ft_strjoin.c \
				libft_lite/ft_strdup.c \
				libft_lite/ft_strlen.c \
				libft_lite/ft_split.c 
						
OBJS		=	${SRCS:.c=.o}

CC			= 	gcc

RM			= 	rm -f

CFLAGS		= 	-Wall -Wextra -Werror

INCLUDES	= 	includes/pipex.h

%.o : %.c		${INCLUDES}
				${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o ${<:.c=.o} 

all:			$(NAME)

$(NAME):		$(OBJS)
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:		
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
