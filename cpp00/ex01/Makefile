NAME=phonebook
CXX=c++
CXX_FLAGS=-Wall -Werror -Wextra -g -std=c++98
SRC_PATH=.
SRC_FILES=main.cpp \
	PhoneBook.cpp \
	Contact.cpp \
	utils.cpp
OBJ_PATH=.
OBJ_FILES=$(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_PATH)/$(OBJ_FILES)
	@echo "Compiling the executable $(NAME)..."
	@$(CXX) $(CXX_FLAGS) $(OBJ_PATH)/$(OBJ_FILES) -o $(NAME)
	@echo "Executable $(NAME) compiled successfully."

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)/$(OBJ_FILES)
	@echo "Object files cleaned successfully."

fclean: clean
	@rm -rf $(NAME)
	@echo "Executable $(NAME) removed successfully."

re: fclean all