#include "PmergeMe.hpp"
#include <algorithm>
#include <limits>
#include <sstream>
#include <utility>
#include <vector>

// Canonical Form
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void)other;
	return *this;
}
PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::generateJacobsthalDiffs(size_t pend_size) {
	if (pend_size == 0) {
		return std::vector<int>();
	}

	std::vector<int> diffs;
	size_t j_prev = 1; // J(n-2), starts at J(1)=1
	size_t j_curr = 1; // J(n-1), starts at J(2)=1
	
	// The first group is always of size 1 (J(2)-J(1))
	diffs.push_back(1);
	
	while (j_curr < pend_size) {
		size_t j_next = j_curr + 2 * j_prev; // J(n) = J(n-1) + 2*J(n-2)
		diffs.push_back(j_next - j_curr);
		j_prev = j_curr;
		j_curr = j_next;
	}

	return diffs;
}
//============================= VECTOR ======================================

// Function to sort using a vector
void PmergeMe::sortVector(const std::vector<int> &sequence) {
	printSequence("Before: ", sequence);

	// Create a vector of structure with the elements
	std::vector<Element> elements;
	for (size_t i = 0; i < sequence.size(); ++i) {
		Element e = {sequence[i], static_cast<int>(i)};
		elements.push_back(e);
	}

	// Check the time spent by the function to sort a vector
	clock_t start = clock();
	fordJohnson(elements);
	clock_t end = clock();

	std::vector<int> sorted_sequence;
	sorted_sequence.reserve(elements.size());
	for (size_t i = 0; i < elements.size(); ++i)
		sorted_sequence.push_back(elements[i].value);

	printSequence("After:  ", sorted_sequence);

	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	std::cout << "Time to process a range of " << sorted_sequence.size()
		  << " elements with std::vector: " << duration << " us" << std::endl;
}

// Function that will recursively sort the elements
void PmergeMe::fordJohnson(std::vector<Element> &mainChain) {
	// In case of only one element there is no need to sort
	if (mainChain.size() <= 1)
		return;

	// In case of an odd number of elements, we leave it separated
	// for inclusion at the end
	Element straggler;
	bool hasStraggler = mainChain.size() % 2 != 0;
	if (hasStraggler) {
		straggler = mainChain.back();
		mainChain.pop_back();
	}

	// 1. Compare elements two by two and separate them into two chains
	// A main chain winnerChain (winners (the largest)) and pend (losers (the smallest))
	std::vector<Element> winnerChain;
	std::vector<PendElement> pend;

	splitIntoWinnersAndLosers(mainChain, winnerChain, pend);

	// 2. RECURSIVE CALL to sort the winner chain (winnerChain).
	//    Now this call does real and significant work.
	fordJohnson(winnerChain);

	// At this moment winnerChain is already sorted
	// Get the first element that will be included in the winner list
	// It is the pair of the smallest winner
	int smallestWinnerOriginalPos = winnerChain[0].winnerIndex;
	Element firstPend = {pend[smallestWinnerOriginalPos].value,
				 pend[smallestWinnerOriginalPos].myOldIndex};

	// index of this vector will be position of loser that will give the current position of its winner pair
	// in the winner list where losers will also be included
	std::vector<int> winnerCurrentPosMap(pend.size());
	// vector index is the position of winner that will give the position of its loser pair
	// this vector will be static and will be used only to get the losers in order of their pairs
	std::vector<int> loserIdxMap(pend.size());

	// Build the INDEX MAP
	buildIndexMaps(winnerChain, pend, winnerCurrentPosMap, loserIdxMap);

	// 4. Insert the elements from `pend` into `winnerChain`
	winnerChain.insert(winnerChain.begin(), firstPend);

	// Since a loser entered winnerChain in the first position
	// we need to update the position of all winners that were in this list
	for (size_t i = 0; i < winnerCurrentPosMap.size(); ++i)
		winnerCurrentPosMap[i]++;

	insertPendingElements(winnerChain, pend, winnerCurrentPosMap, loserIdxMap);

	if (hasStraggler) {
		std::vector<Element>::iterator insert_pos = std::lower_bound(
			winnerChain.begin(), winnerChain.end(), straggler.value, PmergeMe::elementLess);
		winnerChain.insert(insert_pos, straggler);
	}

	mainChain = winnerChain;
}

// Function to create pairs and separate into winners and losers
void PmergeMe::splitIntoWinnersAndLosers(std::vector<Element> &mainChain, std::vector<Element> &winnerChain,
					 std::vector<PendElement> &pend) {
	for (size_t i = 0; i < mainChain.size(); i += 2) {
		Element winner, loser;
		if (mainChain[i].value > mainChain[i + 1].value) {
			winner = mainChain[i];
			loser = mainChain[i + 1];
		} else {
			winner = mainChain[i + 1];
			loser = mainChain[i];
		}

		// In practice mainChain ends up being the set of winners from the previous round
		// When we separate mainChain we need to keep what was the position of elements in it
		// This information will be stored by the loser element
		int partnerOldIndex = winner.winnerIndex;
		// The winners will carry their position in the winner list,
		// so we can know what their position was before being sorted
		winner.winnerIndex = winnerChain.size();
		winnerChain.push_back(winner);

		PendElement p = {loser.value, loser.winnerIndex, partnerOldIndex};
		pend.push_back(p);
	}
}

// Auxiliary function to build the index maps after sorting
void PmergeMe::buildIndexMaps(std::vector<Element> &winnerChain, std::vector<PendElement> &pend,
				  std::vector<int> &winnerCurrentPosMap, std::vector<int> &loserIdxMap) {

	for (size_t i = 0; i < winnerChain.size(); ++i) {
		// winnerChain[i].winnerIndex has the position BEFORE sorting
		int winnerPositionBeforeSorting = winnerChain[i].winnerIndex;

		// the vector index is the position of loser in pend and i informs where its winner pair is
		winnerCurrentPosMap[winnerPositionBeforeSorting] = i;

		// loserIdxMap[i] tells what is the index of the loser associated with the winner at position i
		// pendMap[i] tells what is the index of the loser (in `pend`) associated with the winner at position `i` of sorted winnerChain
		// that is, we manage to "sort" the losers according to their pairs
		loserIdxMap[i] = winnerPositionBeforeSorting;

		// Since I already have the relationship of each loser with the winner through the map,
		// I can already set the winner's index to the index it had in mainChain
		winnerChain[i].winnerIndex = pend[winnerPositionBeforeSorting].partnerOldIndex;
	}
}

// Function to insert losers into winnerChain using Jacobsthal sequence
void PmergeMe::insertPendingElements(std::vector<Element> &winnerChain, std::vector<PendElement> &pend,
					 std::vector<int> &winnerCurrentPosMap, std::vector<int> &loserIdxMap) {

	// The algorithm uses the difference of Jacobsthal sequence numbers
	// to define the insertion order of losers and groups
	std::vector<int> jacobsthal_diffs = generateJacobsthalDiffs(pend.size());
	// Since we already inserted the "first" loser
	// The first element (pair of smallest winner) is inserted first, so we start from index 0.
	size_t last_idxmap_used = 0;

	// We start from the second Jacobsthal group (i=1), since the first (size 1) has already been inserted.
	for (size_t i = 1; i < jacobsthal_diffs.size(); ++i) {
		// Define the group to be inserted that goes from group_end or pend size to last_idxmap_used
		size_t group_end = last_idxmap_used + jacobsthal_diffs[i];
		size_t current_idx = std::min(group_end, pend.size() - 1);

		// The insertion of groups occurs in descending order
		while (current_idx > last_idxmap_used) {
			int loserPosInPend = loserIdxMap[current_idx];
			PendElement &p_elem = pend[loserPosInPend];

			// The search limit is the current position of the winner pair.
			int search_limit = winnerCurrentPosMap[loserPosInPend];

			std::vector<Element>::iterator insert_pos =
				std::lower_bound(winnerChain.begin(), winnerChain.begin() + search_limit + 1,
						 p_elem.value, PmergeMe::elementLess);

			int insert_idx = std::distance(winnerChain.begin(), insert_pos);
			// Since the winner list will become the mainChain of the previous function
			// we have to set what was its index in mainChain
			Element to_insert = {p_elem.value, p_elem.myOldIndex};
			winnerChain.insert(insert_pos, to_insert);

			// Update the position of winners
			// only increment those to the right of the inserted position
			for (size_t j = 0; j < winnerCurrentPosMap.size(); ++j) {
				if (winnerCurrentPosMap[j] >= insert_idx)
					winnerCurrentPosMap[j]++;
			}
			current_idx--;
		}
		last_idxmap_used = group_end;
		if (last_idxmap_used >= pend.size() -1)
			break;
	}
}

bool PmergeMe::elementLess(const Element &elem, int val) { return elem.value < val; }

// The printSequence function doesn't change
void PmergeMe::printSequence(const std::string &prefix, const std::vector<int> &container) {
	std::cout << prefix;
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << " " << container[i];
	}
	std::cout << std::endl;
}

void PmergeMe::printSequenceDebug(const std::string &prefix, std::vector<Element> &container) {
	std::cout << prefix;
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << CYAN << " " << container[i].value << "[" << container[i].winnerIndex << "]"
			  << RESET;
	}
	std::cout << std::endl;
}

void PmergeMe::printSequenceDebug(const std::string &prefix, std::vector<PendElement> &container) {
	std::cout << prefix;
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << CYAN << " " << container[i].value << "[" << container[i].myOldIndex << "]"
			  << RESET;
	}
	std::cout << std::endl;
}


// ============================ DEQUE ====================================

// Function to sort using a deque
void PmergeMe::sortDeque(const std::vector<int> &sequence) {

	printSequence("Before: ", sequence);

	// Create a deque of structure with the elements
	std::deque<Element> elements;
	for (size_t i = 0; i < sequence.size(); ++i) {
		Element e = {sequence[i], static_cast<int>(i)};
		elements.push_back(e);
	}

	// Check the time spent by the function to sort a deque
	clock_t start = clock();
	fordJohnson(elements);
	clock_t end = clock();

	std::deque<int> sorted_sequence;
	for (size_t i = 0; i < elements.size(); ++i)
		sorted_sequence.push_back(elements[i].value);

	printSequence("After:  ", sorted_sequence);

	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	std::cout << "Time to process a range of " << sorted_sequence.size()
		  << " elements with std::deque: " << duration << " us" << std::endl;
}

// Function that will recursively sort the elements (deque version)
void PmergeMe::fordJohnson(std::deque<Element> &mainChain) {
	// In case of only one element there is no need to sort
	if (mainChain.size() <= 1)
		return;

	// In case of an odd number of elements, we leave it separated
	// for inclusion at the end
	Element straggler;
	bool hasStraggler = mainChain.size() % 2 != 0;
	if (hasStraggler) {
		straggler = mainChain.back();
		mainChain.pop_back();
	}

	// 1. Compare elements two by two and separate them into two chains
	// A main chain S (winners (the largest)) and pend (losers (the smallest))
	std::deque<Element> winnerChain;
	std::deque<PendElement> pend;

	splitIntoWinnersAndLosers(mainChain, winnerChain, pend);

	// 2. RECURSIVE CALL to sort the winnerChain
	//    Now this call does real and significant work.
	fordJohnson(winnerChain);

	// At this moment winnerChain is already sorted
	// Get the first element that will be included in the winner list
	// It is the pair of the smallest winner
	int smallestWinnerOriginalPos = winnerChain[0].winnerIndex;
	Element firstPend = {pend[smallestWinnerOriginalPos].value,
				 pend[smallestWinnerOriginalPos].myOldIndex};

	// index of this vector will be position of loser that will give the current position of its winner pair
	// in the winner list where losers will also be included
	std::deque<int> winnerCurrentPosMap(pend.size());
	// vector index is the position of winner that will give the position of its loser pair
	// this vector will be static and will be used only to get the losers in order of their pairs
	std::deque<int> loserIdxMap(pend.size());

	// Build the INDEX MAP
	buildIndexMaps(winnerChain, pend, winnerCurrentPosMap, loserIdxMap);

	// 4. Insert the elements from `pend` into `winnerChain`
	winnerChain.insert(winnerChain.begin(), firstPend);

	// Since a loser entered winnerChain in the first position
	// we need to update the position of all winners that were in this list
	for (size_t i = 0; i < winnerCurrentPosMap.size(); ++i)
		winnerCurrentPosMap[i]++;

	insertPendingElements(winnerChain, pend, winnerCurrentPosMap, loserIdxMap);

	if (hasStraggler) {
		std::deque<Element>::iterator insert_pos = std::lower_bound(
			winnerChain.begin(), winnerChain.end(), straggler.value, PmergeMe::elementLess);
		winnerChain.insert(insert_pos, straggler);
	}

	mainChain = winnerChain;
}

void PmergeMe::buildIndexMaps(std::deque<Element> &winnerChain, std::deque<PendElement> &pend,
				  std::deque<int> &winnerCurrentPosMap, std::deque<int> &loserIdxMap) {

	for (size_t i = 0; i < winnerChain.size(); ++i) {
		// winnerChain[i].winnerIndex has the position BEFORE sorting
		int winnerPositionBeforeSorting = winnerChain[i].winnerIndex;

		// the vector index is the position of loser in pend and i informs where its winner pair is
		winnerCurrentPosMap[winnerPositionBeforeSorting] = i;

		// loserIdxMap[i] tells what is the index of the loser associated with the winner at position i
		// pendMap[i] tells what is the index of the loser (in `pend`) associated with the winner at position `i` of sorted winnerChain
		// that is, we manage to "sort" the losers according to their pairs
		loserIdxMap[i] = winnerPositionBeforeSorting;

		// Since I already have the relationship of each loser with the winner through the map,
		// I can already set the winner's index to the index it had in mainChain
		winnerChain[i].winnerIndex = pend[winnerPositionBeforeSorting].partnerOldIndex;
	}
}

// Function to create pairs and separate into winners and losers (deque version)
void PmergeMe::splitIntoWinnersAndLosers(std::deque<Element> &mainChain, std::deque<Element> &winnerChain,
					 std::deque<PendElement> &pend) {
	for (size_t i = 0; i < mainChain.size(); i += 2) {
		Element winner, loser;
		if (mainChain[i].value > mainChain[i + 1].value) {
			winner = mainChain[i];
			loser = mainChain[i + 1];
		} else {
			winner = mainChain[i + 1];
			loser = mainChain[i];
		}

		// In practice mainChain ends up being the set of winners from the previous round
		// When we separate mainChain we need to keep what was the position of elements in it
		// This information will be stored by the loser element
		int partnerOldIndex = winner.winnerIndex;
		// The winners will carry their position in the winner list,
		// so we can know what their position was before being sorted
		winner.winnerIndex = winnerChain.size();
		winnerChain.push_back(winner);

		PendElement p = {loser.value, loser.winnerIndex, partnerOldIndex};
		pend.push_back(p);
	}
}

// Function to insert losers into winnerChain using Jacobsthal sequence (deque version)
void PmergeMe::insertPendingElements(std::deque<Element> &winnerChain, std::deque<PendElement> &pend,
					 std::deque<int> &winnerCurrentPosMap, std::deque<int> &loserIdxMap) {

	// The algorithm uses the difference of Jacobsthal sequence numbers
	// to define the insertion order of losers and groups
	std::vector<int> jacobsthal_diffs = generateJacobsthalDiffs(pend.size());
	// Since we already inserted the "first" loser
	// The first element (pair of smallest winner) is inserted first, so we start from index 0.
	size_t last_idxmap_used = 0;

	// We start from the second Jacobsthal group (i=1), since the first (size 1) has already been inserted.
	for (size_t i = 1; i < jacobsthal_diffs.size(); ++i) {
		// Define the group to be inserted that goes from group_end or pend size to last_idxmap_used
		size_t group_end = last_idxmap_used + jacobsthal_diffs[i];
		size_t current_idx = std::min(group_end, pend.size() - 1);

		// The insertion of groups occurs in descending order
		while (current_idx > last_idxmap_used) {
			int loserPosInPend = loserIdxMap[current_idx];
			PendElement &p_elem = pend[loserPosInPend];

			// The search limit is the current position of the winner pair.
			int search_limit = winnerCurrentPosMap[loserPosInPend];

			std::deque<Element>::iterator insert_pos =
				std::lower_bound(winnerChain.begin(), winnerChain.begin() + search_limit + 1,
						 p_elem.value, PmergeMe::elementLess);

			int insert_idx = std::distance(winnerChain.begin(), insert_pos);
			// Since the winner list will become the mainChain of the previous function
			// we have to set what was its index in mainChain
			Element to_insert = {p_elem.value, p_elem.myOldIndex};
			winnerChain.insert(insert_pos, to_insert);

			// Update the position of winners
			// only increment those to the right of the inserted position
			for (size_t j = 0; j < winnerCurrentPosMap.size(); ++j) {
				if (winnerCurrentPosMap[j] >= insert_idx)
					winnerCurrentPosMap[j]++;
			}
			current_idx--;
		}
		last_idxmap_used = group_end;
		if (last_idxmap_used >= pend.size() - 1)
			break;
	}
}

void PmergeMe::printSequenceDebug(const std::string &prefix, std::deque<Element> &container) {
	std::cout << prefix;
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << CYAN << " " << container[i].value << "[" << container[i].winnerIndex << "]"
			  << RESET;
	}
	std::cout << std::endl;
}

void PmergeMe::printSequenceDebug(const std::string &prefix, std::deque<PendElement> &container) {
	std::cout << prefix;
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << CYAN << " " << container[i].value << "[" << container[i].myOldIndex << "]"
			  << RESET;
	}
	std::cout << std::endl;
}

void PmergeMe::printSequence(const std::string &prefix, const std::deque<int> &container) {
	std::cout << prefix;
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << " " << container[i];
	}
	std::cout << std::endl;
}