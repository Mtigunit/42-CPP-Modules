# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 14:39:59 by mtigunit          #+#    #+#              #
#    Updated: 2023/06/10 08:29:03 by mtigunit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS		=	main.cpp Contact.cpp phoneBook.cpp
OBJS		=	$(SRCS:%.cpp=%.o)
NAME		=	myAwesomePhoneBook
INCLUDE		=	Contact.hpp phoneBook.hpp

all:			$(NAME)

%.o:			%.cpp $(INCLUDE)
				@echo "\033[1;34mcompiling $<...\033[0m"
				@$(CXX) $(CXXFLAGS) -c $<

$(NAME):		$(OBJS)
				@$(CXX) $(OBJS) -o $(NAME)
				@echo "\033[1;32m---DONE!---\033[0m"

clean:
				@echo "\033[1;35mRemoving $(OBJS)...\033[0m"
				@rm -rf $(OBJS)
				@sleep 0.5;
				@echo "\033[1;32m---DONE!---\033[0m"

fclean:			clean
				@echo "\033[1;35mRemoving $(NAME)...\033[0m"
				@rm -rf $(NAME)
				@sleep 0.5;
				@echo "\033[1;32m---DONE!---\033[0m"

re:				fclean all
