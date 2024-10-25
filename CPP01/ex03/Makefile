NAME = Fight

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ = $(SRC:%.cpp=%.o)

COLOR = \033[1;32m
RESET = \033[0m

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "$(COLOR)Compiling... please wait ...$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: re
	@echo "$(COLOR)Running the program...$(RESET)"
	@./$(NAME)

.PHONY: all clean fclean re run
