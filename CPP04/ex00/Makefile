NAME = Animal

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp
HEADERS = Animal.hpp Cat.hpp Dog.hpp

OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all