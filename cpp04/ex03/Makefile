# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 08:04:22 by yusengok          #+#    #+#              #
#    Updated: 2024/07/19 12:09:02 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = IMateriaSource

vpath %.cpp srcs
FILES = main \
		Materia	\
		Ice	\
		Cure	\
		MateriaSource	\
		Character
SRCS = $(addsuffix .cpp, $(FILES))

INCLUDE = includes/
HEADER_FILEES = Materia	\
				Ice	\
				Cure	\
				MateriaSource	\
				Character
HEADERS = $(addprefix $(INCLUDE), $(addsuffix .hpp, $(HEADER_FILES)))

OBJS_DIR = .objs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
DEPS = $(OBJS:.o=.d)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCLUDE)

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

