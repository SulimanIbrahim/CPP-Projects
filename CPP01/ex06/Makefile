NAME = harlFilter

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

SRC = main.cpp Harl.cpp
HEADERS = Harl.hpp
OBJ = $(SRC:%.cpp=%.o)

COLOR = \033[1;32m
RESET = \033[0m

all : $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	@echo "$(COLOR)Done.$(RESET)"
	@$(CXX) $(CXXFLAGS)  -o $(NAME) $(OBJ) 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: re
	@echo "$(COLOR)Running the program...$(RESET)"
	@./$(NAME)

.PHONY: all clean fclean re run
