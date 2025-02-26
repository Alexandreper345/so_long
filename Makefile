NAME = so_long
PRINTF = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCC_GNL = get_next_line.c get_next_line_utils.c
SRCC_MAIN = main.c
SRCC_EXTERNAL_FN = ft_strlcpy.c
SRCC_ERROR = this_rectangle.c frees.c fd_error.c
SRCC_SIZE = len_height.c len_width.c
SRC_DIR = Get_next_line/
SRC_DIR_ERROR = Erro_Handling/
SRC_DIR_SIZE = sizes_gnl/
SRC_DIR_EXTERNAL_FN = external_function/

SRC_GNL = $(addprefix $(SRC_DIR), $(SRCC_GNL))
SRC_ERROR = $(addprefix $(SRC_DIR_ERROR),$(SRCC_ERROR))
SRC_SIZE = $(addprefix $(SRC_DIR_SIZE), $(SRCC_SIZE))
SRC_EX_FN = $(SRC_DIR_EXTERNAL_FN)$(SRCC_EXTERNAL_FN)
OBJS_MAIN = $(SRCC_MAIN:.c=.o)
OBJS_GNL = $(SRC_GNL:.c=.o)
OBJS_ERROR = $(SRC_ERROR:.c=.o)
OBJS_SIZE = $(SRC_SIZE:.c=.o)
OBJS_EX_FN = $(SRC_EX_FN:.c=.o)

all: $(NAME)

${NAME}: ${OBJS_MAIN} ${OBJS_GNL} ${OBJS_ERROR} ${OBJS_SIZE} ${OBJS_EX_FN}
	@make -C Printf
	$(CC) $(FLAGS) $(OBJS_MAIN) $(OBJS_GNL) $(OBJS_ERROR) $(OBJS_SIZE) ${OBJS_EX_FN} Printf/${PRINTF} -o ${NAME} -g

clean:
	@make clean -C Printf
	${RM} ${OBJS_MAIN}
	${RM} ${OBJS_GNL}
	${RM} $(OBJS_ERROR)
	${RM} $(OBJS_SIZE)
	${RM} ${OBJS_EX_FN}

fclean: clean
	@make clean -C Printf
	${RM} ${NAME}
	${RM} Printf/${PRINTF}

re: fclean all
