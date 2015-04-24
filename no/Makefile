NAME		=	libno.a
SRC_DIR		=	src/
SRC			=	$(addprefix $(SRC_DIR), $(shell ls -1 src | grep "cpp"))
INCS		=	$(subst .cpp,.hpp,$(SRC))
OBJ			=	$(subst .cpp,.o,$(SRC))

CC			=	clang++
FLAGS		=	-Wall -Werror -Wextra

SFML-PATH	=	../SFML-2.2

INC			=	-Iinc
INC			+=	-I$(SFML-PATH)/include
# INC		+=	-Ilua-5.3.0/src/

LIBS		=	-L$(SFML-PATH)/lib
LIBS		+=	-lsfml-graphics
LIBS		+=	-lsfml-window
LIBS		+=	-lsfml-system
# LIBS	+=	-lsfml-audio
# LIBS	+=	-lsfml-network

#LIBS	+=	-Llib/lua-5.3.0/src/
#LIBS	+=	-llua

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $< $(INC)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
