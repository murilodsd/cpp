NAME=megaphone
CXX=c++
CXX_FLAGS=-Wall -Werror -Wextra -g -std=c++98
SRC_PATH=.
SRC_FILES=megaphone.cpp
OBJ_PATH=.
OBJ_FILES=$(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_PATH)/$(OBJ_FILES)
	@echo "Compiling the executable $(NAME)..."
	@$(CPP) $(CPP_FLAGS) $(OBJ_PATH)/$(OBJ_FILES) -o $(NAME)
	@echo "Executable $(NAME) compiled successfully."

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)/$(OBJ_FILES)
	@echo "Object files cleaned successfully."

fclean: clean
	@rm -rf $(NAME)
	@echo "Executable $(NAME) removed successfully."

re: fclean all