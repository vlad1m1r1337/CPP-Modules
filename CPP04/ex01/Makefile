NAME = ex01
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror  -std=c++98
OBJS = $(SRCS:.cpp=.o)
HEADERS = Animal.h Dog.h Cat.h WrongAnimal.h WrongCat.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
