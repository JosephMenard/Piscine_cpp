# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 16:58:06 by jmenard           #+#    #+#              #
#    Updated: 2025/03/21 12:25:41 by jmenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = AMateria.hpp Character.hpp ICharacter.hpp Cure.hpp Ice.hpp

SRC = AMateria.cpp Character.cpp ICharacter.cpp Cure.cpp Ice.cpp main.cpp

NAME = AMateria

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
	rm -rf $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re