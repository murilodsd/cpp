NAME=account
CPP=c++
CPP_FLAGS=-Wall -Werror -Wall -g -std=c++98
SRC_PATH=.
SRC_FILES=tests.cpp \
	Account.cpp
OBJ_PATH=.
OBJ_FILES=$(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_PATH)/$(OBJ_FILES)
	$(CPP) $(CPP_FLAGS) $(OBJ_PATH)/$(OBJ_FILES) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)/$(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all