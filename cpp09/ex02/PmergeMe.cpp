#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <algorithm> // Para std::lower_bound
#include <cmath>     // Para pow
#include <sstream>   // Para std::stringstream
#include <iomanip>   // Para std::setprecision

// --- Constructor

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe&) {}
PmergeMe& PmergeMe::operator=(const PmergeMe&) { return *this; }
PmergeMe::~PmergeMe() {}

// --- Lógica Principal (Implementação do Template) ---

// Implementação da função Jacobsthal
int PmergeMe::jacobsthal(int k) {
	if (k < 0)
		return 0;
	// Usamos a fórmula explícita: J(k) = (2^k - (-1)^k) / 3
	return static_cast<int>((pow(2, k) - pow(-1, k)) / 3.0);
}


void PmergeMe::mergeInsertSortRecursive(std::vector<int>& container) {
	if (container.size() <= 1) {
		return;
	}

	// --- PASSO 1: Preparação ---
	int stray = -1;
	bool hasStray = (container.size() % 2 != 0);
	if (hasStray) {
		stray = container.back();
		container.pop_back();
	}

	std::vector<MainChainElement> mainChainStructs;
	std::vector<PendElementInfo> pendInfo;

	for (size_t i = 0; i < container.size() / 2; ++i) {
		int first = container[i * 2];
		int second = container[i * 2 + 1];

		if (first > second) {
			mainChainStructs.push_back((MainChainElement){first, static_cast<int>(i)});
			pendInfo.push_back((PendElementInfo){second, static_cast<int>(i)});
		} else {
			mainChainStructs.push_back((MainChainElement){second, static_cast<int>(i)});
			pendInfo.push_back((PendElementInfo){first, static_cast<int>(i)});
		}
	}

	// --- PASSO 2: Chamada Recursiva ---
	// Criar um contentor temporário de valores para a chamada recursiva
	std::vector<int> mainChainValues;
	for(size_t i = 0; i < mainChainStructs.size(); ++i)
		mainChainValues.push_back(mainChainStructs[i].value);
	mergeInsertSortRecursive(mainChainValues);

	// --- PASSO 3: Criar Mapa de Índices ---
	std::vector<int> partnerCurrentIndices(mainChainStructs.size());
	for (size_t new_idx = 0; new_idx < mainChainValues.size(); ++new_idx) {
		for (size_t old_idx = 0; old_idx < mainChainStructs.size(); ++old_idx) {
			if (mainChainValues[new_idx] == mainChainStructs[old_idx].value) {
				partnerCurrentIndices[mainChainStructs[old_idx].original_index] = new_idx;
				mainChainStructs[old_idx].value = -1; // Marcar como usado para lidar com duplicados
				break;
			}
		}
	}

	// A mainChain agora é a mainChainValues ordenada
	std::vector<int>& mainChain = mainChainValues;

	if (hasStray)
		pendInfo.push_back((PendElementInfo){stray, -1});

	// --- PASSO 4: Inserção com Atualização Manual de Índices ---
	if (!pendInfo.empty()) {
		mainChain.insert(mainChain.begin(), pendInfo[0].value);
		for (size_t i = 0; i < partnerCurrentIndices.size(); ++i)
			partnerCurrentIndices[i]++;
		pendInfo.erase(pendInfo.begin());
	}

	int last_jacob = 0;
	for (int k = 3; ; ++k) {
		int current_jacob_idx = jacobsthal(k);
		int group_end = std::min(current_jacob_idx, static_cast<int>(pendInfo.size()));

		for (int i = group_end - 1; i >= last_jacob; --i) {
			int element_to_insert = pendInfo[i].value;
			int original_partner_idx = pendInfo[i].original_partner_index;

			std::vector<int>::iterator search_limit;
			if (original_partner_idx == -1) {
				search_limit = mainChain.end();
			} else {
				int new_partner_idx = partnerCurrentIndices[original_partner_idx];
				search_limit = mainChain.begin() + new_partner_idx;
			}
			
			std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), search_limit, element_to_insert);
			int insertion_idx = std::distance(mainChain.begin(), insertPos);
			
			mainChain.insert(insertPos, element_to_insert);

			for (size_t j = 0; j < partnerCurrentIndices.size(); ++j) {
				if (partnerCurrentIndices[j] >= insertion_idx) {
					partnerCurrentIndices[j]++;
				}
			}
		}

		if (group_end == static_cast<int>(pendInfo.size()))
			break;
		last_jacob = group_end;
	}

	container = mainChain;
}

void PmergeMe::sortVector(int argc, char **argv) {
	std::vector<int> vec;
	for (int i = 1; i < argc; ++i) {
		long val;
		std::stringstream ss(argv[i]);
		ss >> val;
		// Validações adicionais (duplicados, etc.) podem ser adicionadas aqui
		vec.push_back(static_cast<int>(val));
	}

	// Imprimir sequência original
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << (i == vec.size() - 1 ? "" : " ");
	std::cout << std::endl;

	// Medir o tempo
	struct timeval start, end;
	gettimeofday(&start, NULL);

	mergeInsertSortRecursive(vec);

	gettimeofday(&end, NULL);
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	double elapsed = seconds * 1e6 + microseconds;

	// Imprimir sequência ordenada e tempo
	std::cout << "After:  ";
	for (size_t i = 0; i < vec.size(); ++i) 
		std::cout << vec[i] << (i == vec.size() - 1 ? "" : " ");
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << std::fixed
		<< std::setprecision(5) << elapsed << " us" << std::endl;
}


// std::deque ###
void PmergeMe::mergeInsertSortRecursive(std::deque<int>& container) {
	if (container.size() <= 1) {
		return;
	}

	int stray = -1;
	bool hasStray = (container.size() % 2 != 0);
	if (hasStray) {
		stray = container.back();
		container.pop_back();
	}

	std::vector<MainChainElement> mainChainStructs;
	std::vector<PendElementInfo> pendInfo;

	for (size_t i = 0; i < container.size() / 2; ++i) {
		int first = container[i * 2];
		int second = container[i * 2 + 1];

		if (first > second) {
		mainChainStructs.push_back((MainChainElement){first, static_cast<int>(i)});
		pendInfo.push_back((PendElementInfo){second, static_cast<int>(i)});
		} else {
		mainChainStructs.push_back((MainChainElement){second, static_cast<int>(i)});
		pendInfo.push_back((PendElementInfo){first, static_cast<int>(i)});
		}
	}

	std::deque<int> mainChainValues;
	for(size_t i = 0; i < mainChainStructs.size(); ++i) {
		mainChainValues.push_back(mainChainStructs[i].value);
	}
	mergeInsertSortRecursive(mainChainValues);

	std::vector<int> partnerCurrentIndices(mainChainStructs.size());
	for (size_t new_idx = 0; new_idx < mainChainValues.size(); ++new_idx) {
		for (size_t old_idx = 0; old_idx < mainChainStructs.size(); ++old_idx) {
		if (mainChainValues[new_idx] == mainChainStructs[old_idx].value && mainChainStructs[old_idx].value != -1) {
			partnerCurrentIndices[mainChainStructs[old_idx].original_index] = new_idx;
			mainChainStructs[old_idx].value = -1;
			break;
		}
		}
	}
	
	std::deque<int>& mainChain = mainChainValues;

	if (hasStray) {
		pendInfo.push_back((PendElementInfo){stray, -1});
	}

	if (!pendInfo.empty()) {
		mainChain.insert(mainChain.begin(), pendInfo[0].value);
		for (size_t i = 0; i < partnerCurrentIndices.size(); ++i) {
		partnerCurrentIndices[i]++;
		}
		pendInfo.erase(pendInfo.begin());
	}

	int last_jacob = 0;
	for (int k = 3; ; ++k) {
		int current_jacob_idx = jacobsthal(k);
		int group_end = std::min(current_jacob_idx, static_cast<int>(pendInfo.size()));

		for (int i = group_end - 1; i >= last_jacob; --i) {
		int element_to_insert = pendInfo[i].value;
		int original_partner_idx = pendInfo[i].original_partner_index;

		std::deque<int>::iterator search_limit;
		if (original_partner_idx == -1) {
			search_limit = mainChain.end();
		} else {
			int new_partner_idx = partnerCurrentIndices[original_partner_idx];
			search_limit = mainChain.begin() + new_partner_idx;
		}
		
		std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), search_limit, element_to_insert);
		int insertion_idx = std::distance(mainChain.begin(), insertPos);
		
		mainChain.insert(insertPos, element_to_insert);

		for (size_t j = 0; j < partnerCurrentIndices.size(); ++j) {
			if (partnerCurrentIndices[j] >= insertion_idx) {
			partnerCurrentIndices[j]++;
			}
		}
		}

		if (group_end == static_cast<int>(pendInfo.size())) break;
		last_jacob = group_end;
	}
	container = mainChain;
}

// std::deque ###
void PmergeMe::sortDeque(int argc, char **argv) {
	std::deque<int> deq;
	for (int i = 1; i < argc; ++i) {
		long val;
		std::stringstream ss(argv[i]);
		ss >> val;
		deq.push_back(static_cast<int>(val));
	}

	struct timeval start, end;
	gettimeofday(&start, NULL);

	mergeInsertSortRecursive(deq);

	gettimeofday(&end, NULL);

	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	double elapsed = seconds * 1e6 + microseconds;

	std::cout << "Time to process a range of " << deq.size()
		<< " elements with std::deque  : " << std::fixed
		<< std::setprecision(5) << elapsed << " us" << std::endl;
}