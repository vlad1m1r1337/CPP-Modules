NAME = executable
SRCS = main.cpp
OBJDIR = obj/
OBJS = $(SRCS:%.cpp=$(OBJDIR)%.o)
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
#HEADER = A.hpp B.hpp C.hpp

all: $(NAME)

$(OBJDIR)%.o: %.cpp #$(HEADER)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	$(shell mkdir -p $(dir $(OBJDIR)))

$(NAME): $(OBJDIR) $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
