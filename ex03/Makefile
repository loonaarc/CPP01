CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
INCLDS = HumanA.hpp HumanB.hpp Weapon.hpp
OBJS = $(SRCS:.cpp=.o)
NAME = unnecessary_violence

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCLDS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re