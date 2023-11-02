NAME = zombie
SRCS = main.cpp Zombie.cpp
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	@@rm -rf $(OBJS)

fclean: clean
	@@rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fcleanre