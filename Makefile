NAME = so_long
PRINTF = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCC_GNL = get_next_line.c get_next_line_utils.c
SRCC_MAIN = main.c
SRCC_ERROR = this_rectangle.c
SRC_DIR = Get_next_line/
SRC_DIR_ERROR = Erro_Handling/

SRC_GNL = $(addprefix $(SRC_DIR), $(SRCC_GNL))
SRC_ERROR = $(SRC_DIR_ERROR)$(SRCC_ERROR)
OBJS_MAIN = $(SRCC_MAIN:.c=.o)
OBJS_GNL = $(SRC_GNL:.c=.o)
OBJS_ERROR = $(SRC_ERROR:.c=.o)

all: $(NAME)

${NAME}: ${OBJS_MAIN} ${OBJS_GNL} ${OBJS_ERROR}
	@make -C Printf
	$(CC) $(FLAGS) $(OBJS_MAIN) $(OBJS_GNL) $(OBJS_ERROR) Printf/${PRINTF} -o ${NAME} -g

clean:
	@make clean -C Printf
	${RM} ${OBJS_MAIN}
	${RM} ${OBJS_GNL}
	${RM} $(OBJS_ERROR)

fclean: clean
	@make clean -C Printf
	${RM} ${NAME}
	${RM} Printf/${PRINTF}

re: fclean all
