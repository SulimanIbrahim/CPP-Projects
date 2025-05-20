NAME = span

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = Span.hpp
SRC = main.cpp Span.cpp

OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
