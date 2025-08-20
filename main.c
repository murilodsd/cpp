#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

bool initBoard(char*** board, char *input_commands, int width, int height)
{
	bool is_writing = false;

	for (int i = 0; i < height; i++)
	{
		(*board)[i] = (char *)calloc(width + 1, sizeof(char));
	}
	int i = 0;
	int j = 0;
	for (int index = 0; index < strlen(input_commands); index++)
	{
		switch (input_commands[index])
		{
			case 'x':
				is_writing = !is_writing;
				break;
			case 's':
				if (i == height - 1)
					return false;
				i++;
				break;
			case 'w':
				if (i == 0)
					return false;
				i--;
				break;
			case 'd':
				if (j == width - 1)
					return false;
				j++;
				break;
			case 'a':
				if (j == 0)
					return false;
				j--;
				break;
		}
		
		if (is_writing)
			(*board)[i][j] = 1;
	}
}

void print_board(char** board, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			putchar(board[i][j] ? '0' : ' ');
		}
		putchar('\n');
	}
}

int main(int argc, char const *argv[])
{
	char** board = (char **)calloc(atoi(argv[2]) + 1, sizeof(char *));
	int	bytes_lidos;
	char	input_commands[9999];
	bytes_lidos = read(0, input_commands, 9999);

	printf("%s", input_commands);
	initBoard(&board, input_commands, atoi(argv[1]), atoi(argv[2]));
	print_board(board, atoi(argv[1]), atoi(argv[2]));

	return 0;
}
