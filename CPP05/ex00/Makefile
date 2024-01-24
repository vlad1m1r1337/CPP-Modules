NAME = ex00
SRCS = main.cpp
OBJDIR = obj/
OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror  -std=c++98
OBJS = $(SRCS:.cpp=.o)
#HEADERS =

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

$(OBJDIR)%.o: %.cpp
	@$(CCP) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR):
	$(shell mkdir -p $(dir $(OBJS)))

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
