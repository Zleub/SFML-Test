NAME =	bin/Client
INCS =	$(subst .cpp,.hpp,$(SRC))
OBJ =	$(subst .cpp,.o,$(SRC))
SRC =	$(shell ls | grep cpp)

CC		=	clang++
FLAGS	=	-Wall -Werror -Wextra

INC		=	-Iinc
INC		+=	-ISFML-2.2/include
# INC		+=	-Ilua-5.3.0/src/

LIBS	=	-LSFML-2.2/lib
LIBS	+=	-lsfml-graphics
LIBS	+=	-lsfml-window
LIBS	+=	-lsfml-system
LIBS	+=	-lsfml-audio
# LIBS	+=	-lsfml-network

#LIBS	+=	-Llib/lua-5.3.0/src/
#LIBS	+=	-llua

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBS) -rpath SFML-2.2/extlibs

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $< $(INC)

re: fclean all

clean:
	# rm -rf $(OBJ)

fclean:
	# rm -rf $(OBJ)
	# rm -rf $(NAME)
