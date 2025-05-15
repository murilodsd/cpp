NAME=a.out
CXX=c++
CXX_FLAGS=-Wall -Werror -Wextra -g -std=c++98
SRC_PATH=.
SRC_FILES=main.cpp \
	Fixed.cpp
OBJ_PATH=.
OBJ_FILES=$(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_PATH)/$(OBJ_FILES)
	$(CXX) $(CXX_FLAGS) $(OBJ_PATH)/$(OBJ_FILES) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)/$(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all