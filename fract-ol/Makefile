NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L minilibx-linux -lX11 -lXext -g3 minilibx-linux/libmlx_Linux.a
LIBFTDIR = libft
LIBFTPATH = libft/libft.a
SRCS = events.c main.c draw.c error.c init.c mandelbrot.c color.c julia.c utils.c tricorn.c
OBJS = ${SRCS:.c=.o}

#Colors:
BLINK		= \e[5m
GREEN		= \e[92;5;118m
RESET		= \e[0m

.c.o:
		${CC} ${CFLAGS} -g3 -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${LIBFTPATH}
		${CC} ${CFLAGS}  ${OBJS} ${MLXFLAGS} -L${LIBFTDIR} -lft -o ${NAME}
		@printf "${BLINK}${GREEN}   (⌐■_■)ﾉ⌐╦╦═─ - - - - Executable ready. \n${RESET}"

${LIBFTPATH}:
		make -C ${LIBFTDIR}

all: ${NAME}

clean:
		make -C ${LIBFTDIR} clean
		rm -f ${OBJS}

fclean: clean
		make -C ${LIBFTDIR} fclean
		rm -f ${NAME}

re: fclean all

valgrind: ${NAME}
		valgrind --leak-check=full ./${NAME} mandelbrot

.PHONY: all fclean re