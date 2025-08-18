# ex03/Makefile
NAME     := weapon_demo
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
RM       := rm -f

SRCS := main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
 