NAME = whatever

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = Whatever.hpp
SRC = main.cpp

OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all 