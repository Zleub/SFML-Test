NAME		=	bin/test
SRC			=	main.cpp
INCS		=	$(subst .cpp,.hpp,$(SRC))
OBJ			=	$(subst .cpp,.o,$(SRC))

CC			=	clang++
FLAGS		=	-Wall -Werror -Wextra

SFML-PATH	=	SFML-2.2

INC			=	-Iinc
INC			+=	-Ino/inc
INC			+=	-I$(SFML-PATH)/include
# INC		+=	-Ilua-5.3.0/src/

LIBS		=	-L$(SFML-PATH)/lib
LIBS		+=	-lsfml-graphics
LIBS		+=	-lsfml-window
LIBS		+=	-lsfml-system
# LIBS		+=	-lsfml-audio
# LIBS		+=	-lsfml-network

LIBS		+=	-Lno
LIBS		+=	-lno

#LIBS	+=	-Llib/lua-5.3.0/src/
#LIBS	+=	-llua

.PHONY: all re clean fclean

all: _no $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBS) -rpath $(SFML-PATH)/extlibs

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $< $(INC)

_no:
	@make -C no

re: fclean all

clean:
	make -C no clean
	rm -rf $(OBJ)

fclean:
	make -C no fclean
	rm -rf $(OBJ)
	rm -rf $(NAME)
