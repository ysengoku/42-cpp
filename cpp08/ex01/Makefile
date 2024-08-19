# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 14:27:10 by yusengok          #+#    #+#              #
#    Updated: 2024/08/19 10:09:42 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span

vpath %.cpp srcs
FILES = main	\
		Span
SRCS = $(addsuffix .cpp, $(FILES))

INCLUDE = includes/
HEADER_FILEES = Span
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
