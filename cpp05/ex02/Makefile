INCLUDES = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

SRC = Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp main.cpp

NAME = AForm

OBJ_DIR = temp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

FLAGS = -std=c++98 -g -Wall -Werror -Wextra

CC = c++

DEP = $(OBJ:.o=.d)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) Shrubbery_shrubbery

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re