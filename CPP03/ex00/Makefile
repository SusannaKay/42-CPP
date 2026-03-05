NAME = ClapTrap
SOURCE = main.cpp ClapTrap.cpp
OBJ = $(SOURCE:.cpp=.o)
FLAGS = -Wall -Wextra -Werror  -std=c++98


all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re