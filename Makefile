CC = gcc
CFLAGS += -Wall -Wl,--defsym=main=start
CPPFLAGS +=
LDFLAGS +=

SRC		= 	main.c 				\
		source/bitshift.c 	\
		source/link_list.c

OBJ		=	${SRC:.c=.o}

NAME	=	tricks

RM = rm -rf

all:	${NAME}

${NAME}:		${OBJ}
	@echo "---- MAKEFILE ALL BEGIN ----"
	${CC} -o ${NAME} ${CFLAGS} ${OBJ}
	@echo "---- MAKEFILE ALL END ----"

clean:
	@echo "---- MAKEFILE CLEAN BEGIN ----"
	${RM} ${OBJ}
	${RM} ${NAME}
	@echo "---- MAKEFILE CLEAN END ----"