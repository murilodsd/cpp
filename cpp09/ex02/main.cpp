#include "PmergeMe.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <string>

std::vector<int> parseAndValidateInput(int argc, char **argv) {
	if (argc < 2) {
		throw std::runtime_error("Error: No numbers to sort.");
	}

	std::vector<int> sequence;

	for (int i = 1; i < argc; ++i) {
		// Validate that all characters are digits
		for (int j = 0; argv[i][j] != '\0'; ++j) {
			if (!std::isdigit(argv[i][j])) {
				throw std::runtime_error(
					"Error: Invalid character in input.");
			}
		}

		// Convert string to number and validate range
		std::stringstream ss(argv[i]);
		long num;
		ss >> num;

		if (ss.fail() || !ss.eof() || num <= 0 ||
			num > std::numeric_limits<int>::max()) {
			throw std::runtime_error("Error: invalid input.");
		}

		// Check for duplicate values in sequence
		for (size_t j = 0; j < sequence.size(); ++j) {
			if (sequence[j] == static_cast<int>(num)) {
				throw std::runtime_error(
					"Error: duplicate numbers are not "
					"allowed.");
			}
		}

		sequence.push_back(static_cast<int>(num));
	}

	return sequence;
}

int main(int argc, char **argv) {
	try {
		std::vector<int> sequence = parseAndValidateInput(argc, argv);

		PmergeMe::sortVector(sequence);
		PmergeMe::sortDeque(sequence);

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}