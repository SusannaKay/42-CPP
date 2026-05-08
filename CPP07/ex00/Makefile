NAME = ex00
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)
$(NAME) :$(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

%o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re