# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 11:50:42 by yusengok          #+#    #+#              #
#    Updated: 2024/05/23 14:14:34 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniPhoneBook

vpath %.cpp srcs
SRCS = main.cpp \
		PhoneBook.cpp \
		Contact.cpp

INCLUDE = includes/
HEADER_FILEES = PhoneBook.hpp \
				Contact.hpp
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
