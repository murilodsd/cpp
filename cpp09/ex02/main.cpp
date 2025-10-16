#include "PmergeMe.hpp"
#include <string>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <cctype>

bool isValidInput(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: No numbers to sort." << std::endl;
		return false;
	}
	// Adicionar verificação de duplicados
	std::vector<long> check_duplicates;
	for (int i = 1; i < argc; ++i) {
		for (int j = 0; argv[i][j] != '\0'; ++j) {
			if (!std::isdigit(argv[i][j])) {
				std::cerr << "Error: Invalid character in input." << std::endl;
				return false;
			}
		}

		long val = std::atol(argv[i]);
		if (val <= 0 || val > std::numeric_limits<int>::max()) {
			std::cerr << "Error: Number out of positive integer range." << std::endl;
			return false;
		}

		if (std::find(check_duplicates.begin(), check_duplicates.end(), val) != check_duplicates.end()) {
			std::cerr << "Error: Duplicate numbers are not allowed." << std::endl;
			return false;
		}
		check_duplicates.push_back(val);
	}
	return true;
}

int main(int argc, char **argv) {
    if (!isValidInput(argc, argv)) {
        return 1;
    }

    PmergeMe::sortVector(argc, argv);
    PmergeMe::sortDeque(argc, argv); 

    return 0;
}