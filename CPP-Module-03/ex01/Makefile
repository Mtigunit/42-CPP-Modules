CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS		= ClapTrap.cpp main.cpp ScavTrap.cpp
OBJS		= $(SRCS:%.cpp=%.o)
NAME		= ClapTrap
INCLUDE		= ClapTrap.hpp ScavTrap.hpp

all:		$(NAME)

%.o:		%.cpp $(INCLUDE)
			@echo "\033[1;34mcompiling $<...\033[0m"
			@$(CXX) $(CXXFLAGS) -c $<

$(NAME):	$(OBJS)
			@$(CXX) $(OBJS) -o $(NAME)
			@echo "\033[1;32m---DONE!---\033[0m"

clean:
			@echo "\033[1;35mRemoving $(OBJS)...\033[0m"
			@rm -rf $(OBJS)
			@sleep 0.5;
			@echo "\033[1;32m---DONE!---\033[0m"

fclean:		clean
			@echo "\033[1;35mRemoving $(NAME)...\033[0m"
			@rm -rf $(NAME)
			@sleep 0.5;
			@echo "\033[1;32m---DONE!---\033[0m"

re:			fclean all

.PHONY: all clean fclean re