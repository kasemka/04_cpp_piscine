NAME	= karenFilter

OBJ	= $(SRC:.cpp=.o)
SRC	= $(wildcard *.cpp)
FLAGS	= -Wall -Wextra -Werror -Werror=implicit-fallthrough=0
CXX	= c++
CXXFLAGS += -std=c++98 $(FLAGS)

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re


