CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98 -Iincludes

NAME    = phonebook

SRC_DIR = src

SRCS    = main.cpp \
		  src/Contact.cpp \
		  src/PhoneBook.cpp

OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re