#include "PmergeMe.hpp"
#include <algorithm>
#include <limits>
#include <sstream>
#include <utility>
#include <vector>

// Forma Canônica
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void)other;
	return *this;
}
PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::generateJacobsthalDiffs(size_t pend_size) {
	std::vector<int> diffs;

	if (pend_size <= 1)
		return diffs;

	// Jacobsthal: J0=0, J1=1, Jn=J(n-1)+2*J(n-2)
	std::vector<size_t> j;
	j.push_back(0);
	j.push_back(1);

	// garante pelo menos até J3
	while (j.size() < 4) {
		size_t next0 = j[j.size() - 1];
		size_t next1 = j[j.size() - 2];
		j.push_back(next0 + 2 * next1);
	}

	size_t covered = 0;
	for (size_t i = 3; covered < pend_size - 1; ++i) {
		// assegura J[i]
		while (j.size() <= i) {
			size_t next0 = j[j.size() - 1];
			size_t next1 = j[j.size() - 2];
			j.push_back(next0 + 2 * next1);
		}

		size_t d = j[i] - j[i - 1]; // 2, 2, 6, 10, 22, ...
		if (d > static_cast<size_t>(std::numeric_limits<int>::max()))
			d = static_cast<size_t>(std::numeric_limits<int>::max());
		diffs.push_back(static_cast<int>(d));

		size_t remaining = (pend_size - 1) - covered;
		size_t use = (d < remaining) ? d : remaining;
		covered += use;
	}

	return diffs;
}
//============================= VECTOR ======================================

// Função para ordenar utilzando um vector
void PmergeMe::sortVector(const std::vector<int> &sequence) {
	std::cout << "=== INICIO sortVector ===" << std::endl;

	printSequence("Before: ", sequence);

	// Criamos um vector de estrutura com os elementos
	std::vector<Element> elements;
	for (size_t i = 0; i < sequence.size(); ++i) {
		Element e = {sequence[i], static_cast<int>(i)};
		elements.push_back(e);
	}

	// Verificamos o tempo gasto pela função para ordenar um vector
	std::cout << "Chamando fordJohnson..." << std::endl;
	clock_t start = clock();
	fordJohnson(elements);
	clock_t end = clock();
	std::cout << "fordJohnson finalizado." << std::endl;

	std::vector<int> sorted_sequence;
	for (size_t i = 0; i < elements.size(); ++i) {
		sorted_sequence.push_back(elements[i].value);
	}

	printSequence("After:  ", sorted_sequence);

	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	std::cout << "Time to process a range of " << sorted_sequence.size()
		  << " elements with std::vector: " << duration << " us" << std::endl;
	std::cout << "=== FIM sortVector ===" << std::endl;
}

// Função que irá ordenar recursivamente os elementos
void PmergeMe::fordJohnson(std::vector<Element> &mainChain) {
	std::cout << "\n--- fordJohnson chamado com " << mainChain.size() << " elementos ---" << std::endl;
	printSequenceDebug("Numeros: ", mainChain);

	// No caso de apenas um elemento não há necessidade de ordenar
	if (mainChain.size() <= 1) {
		std::cout << "Caso base alcançado (size <= 1), retornando." << std::endl;
		printSequenceDebug("Ordenado: ", mainChain);
		return;
	}

	// No caso de haver um número ímpar de elementos, deixamos ele separado
	// para inclusão ao final
	Element straggler;
	bool hasStraggler = mainChain.size() % 2 != 0;
	if (hasStraggler) {
		straggler = mainChain.back();
		mainChain.pop_back();
		std::cout << "Straggler detectado: " << straggler.value << std::endl;
	}

	std::cout << "ETAPA 1: Criando pares e definindo ganhadores/perdedores..." << std::endl;
	// 1. Comparamos de dois em dois elementos e os separados em duas cadeias
	// Uma cadeia principal S (ganhadores (os maiores)) e a pend(perdedores(os menores))
	std::vector<Element> winnerChain;
	std::vector<PendElement> pend;
	for (size_t i = 0; i < mainChain.size(); i += 2) {
		Element winner, loser;
		if (mainChain[i].value > mainChain[i + 1].value) {
			winner = mainChain[i];
			loser = mainChain[i + 1];
		} else {
			winner = mainChain[i + 1];
			loser = mainChain[i];
		}

		// Na prática a mainChain acaba sendo o conjunto dos ganhadores da rodada anterior
		// Quando separamos a mainChain precisamos guardar qual era a posicao dos elementos nela
		// Essa informação será guardada pelo elemento perdedor
		int partnerOldIndex = winner.winnerIndex;
		// Os ganhadores vao levar sua posicao na lista de ganhadores,
		// para que possamos saber qual era sua posicao antes de ser
		// ordenado
		winner.winnerIndex = winnerChain.size();
		winnerChain.push_back(winner);

		PendElement p = {loser.value, loser.winnerIndex, partnerOldIndex};
		pend.push_back(p);
	}
	std::cout << "winnerChain (ganhadores) size: " << winnerChain.size()
		  << ", pend (perdedores) size: " << pend.size() << std::endl;
	printSequenceDebug("Ganhadores: ", winnerChain);
	printSequenceDebug("Perdedores: ", pend);
	std::cout << "ETAPA 2: Chamada recursiva para ordenar winnerChain de tamanho " << winnerChain.size()
		  << std::endl;
	// 2. CHAMADA RECURSIVA para ordenar a cadeia de ganhadores
	// (winnerChain).
	//    Agora esta chamada faz um trabalho real e significativo.
	fordJohnson(winnerChain);
	std::cout << "winnerChain ordenado após recursão." << std::endl;

	std::cout << "ETAPA 3: Construindo mapa de índices..." << std::endl;
	// 3. Construir o MAPA DE ÍNDICES (lógica inalterada e correta)
	// Pegar o primeiro elemento que sera incluido na lista de ganhadores
	// Ele é o par do menor ganhador
	int smallestWinnerOriginalPos = winnerChain[0].winnerIndex;
	Element firstPend = {pend[smallestWinnerOriginalPos].value,
			     pend[smallestWinnerOriginalPos].myOldIndex};

	std::vector<int> indexMap(pend.size());
	// Nesse momento a winnerChain já está ordenada
	for (size_t i = 0; i < winnerChain.size(); ++i) {
		std::cout << "indice:" << i << std::endl;
		// O indexMap vai falar qual era o index anterior de cada ganhador antes de ordenar
		// O atual elemento da posicao i estava na posicao winnerIndex antes de ordenar
		int winnerPositionBeforeSorting = winnerChain[i].winnerIndex;
		indexMap[i] = winnerPositionBeforeSorting;

		// Como ja tenho a relacao de cada perdedor com o ganhador por meio do map,
		// ja posso setar o index do ganhador para o index que ele possuia na mainChain
		winnerChain[i].winnerIndex = pend[winnerPositionBeforeSorting].partnerOldIndex;
	}

	// Fazemos uma copia aqui pois:
	// indexMap vai ficar controlando
	std::vector<int> indexMapLosers = indexMap;
	printSequence("Mapa de indices:  ", indexMap);
	std::cout << "ETAPA 4: Inserindo elementos de pend em winnerChain..." << std::endl;
	// 4. Inserir os elementos da `pend` na `S` (lógica inalterada)
	winnerChain.insert(winnerChain.begin(), firstPend);
	std::cout << "Primeiro elemento de pend inserido no início: " << firstPend.value << std::endl;

	for (size_t i = 0; i < indexMap.size(); ++i) {
		indexMap[i]++;
	}
	printSequence("Mapa de indices:  ", indexMap);
	std::vector<int> jacobsthal_diffs = generateJacobsthalDiffs(pend.size());
	printSequence("jacobal: ", jacobsthal_diffs);
	size_t last_idxmap_used = 0;

	std::cout << "Inserindo elementos restantes usando sequência Jacobsthal..." << std::endl;
	for (size_t i = 0; i < jacobsthal_diffs.size(); ++i) {
		size_t group_end = last_idxmap_used + jacobsthal_diffs[i];
		size_t current_idx = std::min(group_end, pend.size() - 1);

		std::cout << "  Grupo Jacobsthal " << i << ": processando de " << current_idx << " até "
			  << (last_idxmap_used + 1) << std::endl;
		std::cout << "  indice nos perdedores: " << indexMapLosers[current_idx] << std::endl;

		while (current_idx > last_idxmap_used) {
			PendElement &p_elem = pend[indexMapLosers[current_idx]];

			int search_limit = indexMap[current_idx];

			std::vector<Element>::iterator insert_pos =
			    std::lower_bound(winnerChain.begin(), winnerChain.begin() + search_limit + 1,
					     p_elem.value, CompareElementValue());

			int insert_idx = std::distance(winnerChain.begin(), insert_pos);
			if (p_elem.value == 5) {
				std::cout << CYAN << "search_limit " << search_limit << RESET << std::endl;
				std::cout << CYAN << "/insert_idx " << insert_idx << std::endl;
				std::cout << CYAN << "current_idx " << current_idx << RESET << std::endl;
			}
			// Como a lista de ganhadores vai virar a mainChain
			// temos que setar qual era o seu indice na mainChain
			Element to_insert = {p_elem.value, p_elem.myOldIndex};
			winnerChain.insert(insert_pos, to_insert);

			std::cout << "    Inserido " << p_elem.value << " na posição " << insert_idx
				  << std::endl;

			for (size_t j = (size_t)insert_idx; j < indexMap.size(); ++j)
				indexMap[j]++;
			printSequence("Mapa de indices:  ", indexMap);
			current_idx--;
		}
		last_idxmap_used = group_end;
		if (last_idxmap_used >= pend.size() - 1)
			break;
	}

	if (hasStraggler) {
		std::cout << "ETAPA 5: Inserindo straggler..." << std::endl;
		std::vector<Element>::iterator insert_pos = std::lower_bound(
		    winnerChain.begin(), winnerChain.end(), straggler.value, CompareElementValue());
		winnerChain.insert(insert_pos, straggler);
		std::cout << "Straggler " << straggler.value << " que estava na posicao "
			  << straggler.winnerIndex << " da mainChain foi inserido" << std::endl;
	}

	mainChain = winnerChain;
	printSequenceDebug("Ordenado: ", mainChain);
	std::cout << "--- fordJohnson " << mainChain.size()
		  << " elementos finalizado (retornando mainChain ordenado) ---\n"
		  << std::endl;
}

// A função printSequence não muda
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