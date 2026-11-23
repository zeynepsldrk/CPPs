CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98 -Iincludes

NAME    = animal

SRC_DIR = src

SRCS    = main.cpp \
		  src/Animal.cpp \
		  src/Cat.cpp \
		  src/Dog.cpp \
		  src/Brain.cpp \
		  src/WrongCat.cpp \
 		  src/WrongAnimal.cpp

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