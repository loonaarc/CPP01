CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Zombie.cpp zombieHorde.cpp
INCLDS = Zombie.hpp
OBJS = $(SRCS:.cpp=.o)
NAME = moar_brainz

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