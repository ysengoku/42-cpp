# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 13:38:32 by yusengok          #+#    #+#              #
#    Updated: 2024/06/27 08:37:44 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

vpath %.cpp srcs
FILES = main \
		Zombie \
		newZombie	\
		randomChump
SRCS = $(addsuffix .cpp, $(FILES))

INCLUDE = includes/
HEADER_FILEES = Zombie
HEADERS = $(addprefix $(INCLUDE), $(addsuffix .hpp, $(HEADER_FILES)))

OBJS_DIR = .objs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
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
