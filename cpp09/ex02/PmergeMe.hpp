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
#include <iostream>
#include <string>
#include <vector>

class PmergeMe {
      public:
	// Ponto de entrada público para a ordenação com std::vector
	static void sortVector(const std::vector<int> &sequence);

      private:
	// Estruturas de dados internas para gerir os elementos e seus índices
	struct Element {
		int value;
		int winnerIndex; // guarda a posicao quando for inserido na
				 // lista de ganhadores
	};

	struct PendElement {
		int value;
		int myOldIndex; // guarda a posicao do perdedor na mainChain
		int partnerOldIndex; // guarda a posicao do par ganhador da
				     // mainChain
	};

	// Functor para usar com std::lower_bound em C++98
	// Compara um Element com um valor inteiro.
	struct CompareElementValue {
		bool operator()(const Element &elem, int val) const {
			return elem.value < val;
		}
	};

	// Métodos privados
	static void fordJohnson(std::vector<Element> &container);
	static std::vector<int> generateJacobsthalDiffs(size_t pend_size);
	static void printSequence(const std::string &prefix,
				  const std::vector<int> &container);
	static void printSequenceDebug(const std::string &prefix,
				       std::vector<Element> &container);
	static void printSequenceDebug(const std::string &prefix,
				       std::vector<PendElement> &container);

	// Construtores privados para impedir a instanciação
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
};

#endif // PMERGEME_HPP