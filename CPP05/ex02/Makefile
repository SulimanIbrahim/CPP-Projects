NAME = forms

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp AForm.cpp \
	  ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
	  
HEADERS = Bureaucrat.hpp AForm.hpp \
		  ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)
	rm -rf *_shrubbery

fclean : clean
	rm -rf $(NAME)

re : fclean all 