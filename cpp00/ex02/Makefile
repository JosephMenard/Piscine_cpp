# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseph <joseph@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 13:13:50 by joseph            #+#    #+#              #
#    Updated: 2025/01/04 13:13:51 by joseph           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = Account.hpp

SRC = Account.cpp test.cpp

NAME = test

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
