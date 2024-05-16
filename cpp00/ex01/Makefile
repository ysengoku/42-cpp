# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 11:50:42 by yusengok          #+#    #+#              #
#    Updated: 2024/05/16 15:00:21 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = awesome_phonebook

SRCS = main.cpp \
		phonebook.cpp

INCLUDE = includes/
HEADER_FILEES = PhoneBook.class.hpp \
			Contact.class.hpp
HEADERS = $(addprefix $(INCLUDE), $(HEADER_FILES))

OBJS_DIR = .objs/
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))
DEPS = $(OBJS:.o=.d)

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCLUDE)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $@

$(OBJS_DIR)%.o: %.cpp $(HEADERS) Makefile
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@ -MMD -MP

-include $(DEPS)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
