# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 11:32:51 by yusengok          #+#    #+#              #
#    Updated: 2024/09/04 10:46:58 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

vpath %.cpp srcs
FILES = main PmergeMe
SRCS = $(addsuffix .cpp, $(FILES))

INCLUDE = includes/
HEADER_FILEES = PmergeMe
HEADERS = $(addprefix $(INCLUDE), $(addsuffix .hpp, $(HEADER_FILES)))

OBJS_DIR = .objs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
DEPS = $(OBJS:.o=.d)

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) -I$(INCLUDE) $^ -o $@

$(OBJS_DIR)%.o: %.cpp Makefile
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CPPFLAGS) -I$(INCLUDE) -c $< -o $@ -MMD -MP

-include $(DEPS)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
