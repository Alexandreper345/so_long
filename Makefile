NAME = so_long
PRINTF = libftprintf.a
LBX_LINUX = minilibx-linux
CC = cc -g
FLAGS = -Wall -Wextra -Werror
CFLAGS = -lmlx_Linux  -lX11 -lXext
RM = rm -rf
SRCC_GNL = get_next_line.c get_next_line_utils.c
SRCC_MAIN = main.c
SRCC = error_handling.c init_matriz.c parsing_map.c utils.c flood_fill.c init_mini.c play_map.c  error_handling_2.c error_handling_3.c utils_2.c 
SRC_DIR_SRC = src/
SRC_DIR_GNL = Get_next_line/

SRC = $(addprefix $(SRC_DIR_SRC), $(SRCC))
SRC_GNL = $(addprefix $(SRC_DIR_GNL), $(SRCC_GNL))
OBJS_MAIN = $(SRCC_MAIN:.c=.o)
OBJS_SRC = $(SRC:.c=.o)
OBJS_GNL = $(SRC_GNL:.c=.o)

all: $(NAME)

${NAME} : ${OBJS_MAIN} ${OBJS_GNL} ${OBJS_SRC}
	@make -C Printf
	@make -C minilibx-linux
	$(CC) $(FLAGS) $(OBJS_MAIN) $(OBJS_GNL) $(OBJS_SRC) Printf/$(PRINTF) -o $(NAME)  -L $(LBX_LINUX) $(CFLAGS)
clean:
	@make clean -C Printf
	@make clean -C minilibx-linux
	${RM} ${OBJS_MAIN}  
	${RM} ${OBJS_GNL}
	${RM} ${OBJS_SRC}

fclean: clean
	@make clean -C Printf
	@make clean -C minilibx-linux
	${RM} ${NAME}
	${RM} Printf/${PRINTF}
	${RM} libft/${LIBFT}

re: fclean all