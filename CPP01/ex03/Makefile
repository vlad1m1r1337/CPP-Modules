NAME = violence
SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)
HEADERS = HumanA.h Weapon.h

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
