NAME = Zombie

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Zombie.cpp
OBJ = $(SRC:%.cpp=%.o)
HEADERS = Zombie.hpp
all : $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) 

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all
