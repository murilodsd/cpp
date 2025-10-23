#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#ifndef COLORS
#define COLORS
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#endif

#include <ctime>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

class PmergeMe {
	public:
	// Public entry point for sorting with std::vector
	static void sortVector(const std::vector<int> &sequence);
	static void sortDeque(const std::vector<int> &sequence);

	private:
	// Internal data structures to manage elements and their indices
	struct Element {
		int value;
		int winnerIndex; // stores the position when inserted into the
				 // winners list
	};

	struct PendElement {
		int value;
		int myOldIndex;	     // stores the loser's position in mainChain
		int partnerOldIndex; // stores the winner pair's position in
				     // mainChain
	};

	// Private methods
	static void fordJohnson(std::vector<Element> &container);
	static std::vector<int> generateJacobsthalDiffs(size_t pend_size);

	// Vector
	static void splitIntoWinnersAndLosers(std::vector<Element> &mainChain,
						std::vector<Element> &winnerChain,
						std::vector<PendElement> &pend);
	static void buildIndexMaps(std::vector<Element> &winnerChain, std::vector<PendElement> &pend,
				   std::vector<int> &winnerCurrentPosMap, std::vector<int> &loserIdxMap);
	static void insertPendingElements(std::vector<Element> &winnerChain, std::vector<PendElement> &pend,
					  std::vector<int> &winnerCurrentPosMap,
					  std::vector<int> &loserIdxMap);

	// Deque
	static void buildIndexMaps(std::deque<Element> &winnerChain, std::deque<PendElement> &pend,
					std::deque<int> &winnerCurrentPosMap, std::deque<int> &loserIdxMap);
	static void splitIntoWinnersAndLosers(std::deque<Element> &mainChain,
						 std::deque<Element> &winnerChain,
						 std::deque<PendElement> &pend);
	static void insertPendingElements(std::deque<Element> &winnerChain, std::deque<PendElement> &pend,
					     std::deque<int> &winnerCurrentPosMap,
					     std::deque<int> &loserIdxMap);
	static void fordJohnson(std::deque<Element> &mainChain);

	// Auxiliary functions
	static bool elementLess(const Element &elem, int val);

	// Vector
	static void printSequence(const std::string &prefix, const std::vector<int> &container);
	static void printSequenceDebug(const std::string &prefix, std::vector<Element> &container);
	static void printSequenceDebug(const std::string &prefix, std::vector<PendElement> &container);

	// Deque
	static void printSequenceDebug(const std::string &prefix, std::deque<Element> &container);
	static void printSequenceDebug(const std::string &prefix, std::deque<PendElement> &container);
	static void printSequence(const std::string &prefix, const std::deque<int> &container);

	// Private constructors to prevent instantiation
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
};

#endif // PMERGEME_HPP