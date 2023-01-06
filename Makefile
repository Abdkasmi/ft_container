SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = container

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

%.o: %.cpp
		c++ $(CPPFLAGS) -c $(SRCS)

$(NAME) : $(OBJS)
		c++ $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

