NAME	= phonebook

OBJ	= $(SRC:.cpp=.o)
SRC	= $(wildcard *.cpp)
FLAGS	= -Wall -Wextra -Werror
CXX	= c++
CXXFLAGS += -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $@

$(OBJ): %.o : %.cpp

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re


