#include <iostream>
#include <vector>

void display(std::vector<std::string>& board) {
	std::cout << "Row size: " << std::size(board);
	std::cout << "\nColumn size: " << std::size(board[0]);
}

int main()
{
	std::vector<std::string> board {
		{'Q', 'X', 'X'},
		{'Q', 'X', 'X'},
		{'Q', 'X', 'X'},
		{'Q', 'X', 'X'},
	};

	display(board);
	
	std::cin.get();
}