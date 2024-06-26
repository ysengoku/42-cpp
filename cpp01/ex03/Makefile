# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 15:58:15 by yusengok          #+#    #+#              #
#    Updated: 2024/06/26 16:00:32 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = weapon

vpath %.cpp srcs
SRCS = main.cpp \
		Weapon.cpp \
		HumanA.cpp	\
		HumanB.cpp

INCLUDE = includes/
HEADER_FILEES = Weapon.hpp	\
				HumanA.hpp	\
				HumanB.hpp
HEADERS = $(addprefix $(INCLUDE), $(HEADER_FILES))

OBJS_DIR = .objs/
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))
DEPS = $(OBJS:.o=.d)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCLUDE)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@

$(OBJS_DIR)%.o: %.cpp $(HEADERS) Makefile
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@ -MMD -MP

-include $(DEPS)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
