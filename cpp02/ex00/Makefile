# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 21:02:05 by jmenard           #+#    #+#              #
#    Updated: 2025/03/14 22:03:21 by jmenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = Fixed.hpp

SRC = Fixed.cpp main.cpp

NAME = Fixed

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