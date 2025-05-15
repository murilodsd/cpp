NAME=harlFilter
CXX=c++
CXX_FLAGS=-Wall -Werror -Wextra -g -std=c++98
SRC_PATH=.
SRC_FILES=main.cpp \
	Harl.cpp
OBJ_PATH=.
OBJ_FILES=$(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_PATH)/$(OBJ_FILES)
	@echo "🔨 Compiling and linking the executable $(NAME)..."
	@$(CXX) $(CXX_FLAGS) $(OBJ_PATH)/$(OBJ_FILES) -o $(NAME)
	@echo "✅ Compilation finished! Executable $(NAME) created."

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@echo "🧹 Cleaning object files..."
	@rm -rf $(OBJ_PATH)/$(OBJ_FILES)
	@echo "✅ Object files cleaned."

fclean: clean
	@echo "🗑️ Removing the executable $(NAME)..."
	@rm -rf $(NAME)
	@echo "✅ Executable $(NAME) removed."

re: fclean all