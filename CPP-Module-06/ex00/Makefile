# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 10:25:08 by mtigunit          #+#    #+#              #
#    Updated: 2023/08/12 15:00:31 by mtigunit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX      				= c++
CXXFLAGS 				= -Wall -Wextra -Werror -std=c++98
NAME     				= convert
SOURCES  				= $(addprefix $(SRC_DIR)/, ScalarConverter.cpp main.cpp)
OBJECTS  				= $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
INCLUDES 				= $(addprefix $(INC_DIR)/, ScalarConverter.hpp)
OBJ_DIR  				= ./objects
SRC_DIR  				= ./sources
INC_DIR  				= ./includes

#====== Colors =======#
RESET					= "\033[0m"
RED						= "\033[1;31m"
GREEN					= "\033[1;32m"
YELLOW					= "\033[1;33m"
ORANGE					= "\033[1;34m"
MAGENTA					= "\033[1;35m"
CYAN					= "\033[1;36m"
WHITE					= "\033[1;37m"

all: 					$(NAME)

$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.cpp $(INCLUDES) | $(OBJ_DIR)
						@echo $(YELLOW)Compiling $<...$(RESET)
						@sleep 0.3
						@$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME):				$(OBJECTS)
						@echo $(ORANGE)Linking $(OBJECTS) to $(NAME)...$(RESET)
						@sleep 0.3
						@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
						@echo $(CYAN)$(NAME) is ready!$(RESET)


$(OBJ_DIR):
						@mkdir -p $(OBJ_DIR)
clean:
						@echo $(MAGENTA)Cleaning object files...$(RESET)
						@sleep 0.5
						@rm -rf $(OBJ_DIR)
						@echo $(GREEN)---DONE!---$(RESET)

fclean: 				clean
						@echo $(MAGENTA)Cleaning $(NAME) executable...$(RESET)
						@sleep 0.5
						@rm -f $(NAME)
						@rm -f *_shrubbery
						@echo $(GREEN)---DONE!---$(RESET)

re: 					fclean all

.PHONY: 				all clean fclean re
