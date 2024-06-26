# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 15:25:55 by yusengok          #+#    #+#              #
#    Updated: 2024/06/26 15:42:18 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = HiThisIsBrain

vpath %.cpp srcs
SRCS = main.cpp

OBJS_DIR = .objs/
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))
DEPS = $(OBJS:.o=.d)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@

$(OBJS_DIR)%.o: %.cpp Makefile
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
