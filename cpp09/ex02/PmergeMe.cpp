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
	if (pend_size == 0) {
		return std::vector<int>();
	}

	std::vector<int> diffs;
	size_t j_prev = 1; // J(n-2), starts at J(1)=1
	size_t j_curr = 1; // J(n-1), starts at J(2)=1
	
	// O primeiro grupo é sempre de tamanho 1 (J(2)-J(1))
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
	sorted_sequence.reserve(elements.size());
	for (size_t i = 0; i < elements.size(); ++i)
		sorted_sequence.push_back(elements[i].value);

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

	splitIntoWinnersAndLosers(mainChain, winnerChain, pend);

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

	// Nesse momento a winnerChain já está ordenada
	// Pegar o primeiro elemento que sera incluido na lista de ganhadores
	// Ele é o par do menor ganhador
	int smallestWinnerOriginalPos = winnerChain[0].winnerIndex;
	Element firstPend = {pend[smallestWinnerOriginalPos].value,
			     pend[smallestWinnerOriginalPos].myOldIndex};

	// índice desse vetor será posicao do perdedor que dará a posicao atual do seu par ganhador
	// na lista dos ganhadores onde os perdedores tambem estarao sendo incluidos
	std::vector<int> winnerCurrentPosMap(pend.size());
	// indice do vetor é a posicao do ganhador que dará o posicao do seu par perdedor
	// esse vector sera estatico e sera usado apenas para pegarmos os perdedores na ordem de seus pares
	std::vector<int> loserIdxMap(pend.size());

	// Construir o MAPA DE ÍNDICES
	buildIndexMaps(winnerChain, pend, winnerCurrentPosMap, loserIdxMap);

	std::cout << "ETAPA 4: Inserindo elementos de pend em winnerChain..." << std::endl;
	// 4. Inserir os elementos da `pend` na `winnerChain` (lógica inalterada)
	winnerChain.insert(winnerChain.begin(), firstPend);
	std::cout << "Primeiro elemento de pend inserido no início: " << firstPend.value << std::endl;

	// Como um perdedor entrou na winnerChain na primeira posicao
	// precisamos atualizar a posicao de todos os ganhadores que estavam nessa lista
	for (size_t i = 0; i < winnerCurrentPosMap.size(); ++i)
		winnerCurrentPosMap[i]++;

	printSequence("Mapa de indices:  ", winnerCurrentPosMap);

	insertPendingElements(winnerChain, pend, winnerCurrentPosMap, loserIdxMap);

	if (hasStraggler) {
		std::cout << "ETAPA 5: Inserindo straggler..." << std::endl;
		std::vector<Element>::iterator insert_pos = std::lower_bound(
		    winnerChain.begin(), winnerChain.end(), straggler.value, PmergeMe::elementLess);
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

// Função para criar pares e separar em ganhadores e perdedores
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

		// Na prática a mainChain acaba sendo o conjunto dos ganhadores da rodada anterior
		// Quando separamos a mainChain precisamos guardar qual era a posicao dos elementos nela
		// Essa informação será guardada pelo elemento perdedor
		int partnerOldIndex = winner.winnerIndex;
		// Os ganhadores vao levar sua posicao na lista de ganhadores,
		// para que possamos saber qual era sua posicao antes de ser ordenado
		winner.winnerIndex = winnerChain.size();
		winnerChain.push_back(winner);

		PendElement p = {loser.value, loser.winnerIndex, partnerOldIndex};
		pend.push_back(p);
	}
}

// Função auxiliar para construir os mapas de índices após ordenação
void PmergeMe::buildIndexMaps(std::vector<Element> &winnerChain, std::vector<PendElement> &pend,
			      std::vector<int> &winnerCurrentPosMap, std::vector<int> &loserIdxMap) {

	for (size_t i = 0; i < winnerChain.size(); ++i) {
		// winnerChain[i].winnerIndex possui a posição ANTES da ordenação
		int winnerPositionBeforeSorting = winnerChain[i].winnerIndex;

		// o indice do vetor é posicao do perdedor na pend e o i informa onde seu par ganhador está
		winnerCurrentPosMap[winnerPositionBeforeSorting] = i;

		// loserIdxMap[i] diz qual é o índice do perdedor associado ao ganhador na posicao i
		// pendMap[i] diz qual é o índice do perdedor (em `pend`) associado ao ganhador na posicao `i` da winnerChain ordenada
		// ou seja, conseguimos "ordenar" os perdedores de acordo com os seus pares
		loserIdxMap[i] = winnerPositionBeforeSorting;

		// Como ja tenho a relacao de cada perdedor com o ganhador por meio do map,
		// ja posso setar o index do ganhador para o index que ele possuia na mainChain
		winnerChain[i].winnerIndex = pend[winnerPositionBeforeSorting].partnerOldIndex;
	}
}

// Função para inserir perdedores na winnerChain usando sequência de Jacobsthal
void PmergeMe::insertPendingElements(std::vector<Element> &winnerChain, std::vector<PendElement> &pend,
				     std::vector<int> &winnerCurrentPosMap, std::vector<int> &loserIdxMap) {

	// O algoritmo utiliza a diferença do numeros da sequencia de Jabobstha
	// para definir a ordem de inserção dos perdedores e o grupos
	std::vector<int> jacobsthal_diffs = generateJacobsthalDiffs(pend.size());
	printSequence("jacobsthal: ", jacobsthal_diffs);
	// Como já inserimos o "primeiro" perdedor
	// O primeiro elemento (par do menor vencedor) é inserido primeiro, então começamos do índice 0.
	size_t last_idxmap_used = 0;

	std::cout << "Inserindo elementos restantes usando sequência Jacobsthal..." << std::endl;
	// Começamos do segundo grupo de Jacobsthal (i=1), pois o primeiro (tamanho 1) já foi inserido.
	for (size_t i = 1; i < jacobsthal_diffs.size(); ++i) {
		// Define o grupo a ser inserido que vai de group_end ou tamanho do pend até last_idxmap_used
		size_t group_end = last_idxmap_used + jacobsthal_diffs[i];
		size_t current_idx = std::min(group_end, pend.size() - 1);

		std::cout << "  Grupo Jacobsthal " << i << ": processando de " << current_idx << " até "
			  << (last_idxmap_used + 1) << std::endl;
		std::cout << "  indice nos perdedores: " << loserIdxMap[current_idx] << std::endl;

		// A inserção dos grupos se dá na ordem decrescente
		while (current_idx > last_idxmap_used) {
			int loserPosInPend = loserIdxMap[current_idx];
			PendElement &p_elem = pend[loserPosInPend];

			// O limite da busca é a posição atual do par vencedor.
			int search_limit = winnerCurrentPosMap[loserPosInPend];

			std::vector<Element>::iterator insert_pos =
			    std::lower_bound(winnerChain.begin(), winnerChain.begin() + search_limit + 1,
					     p_elem.value, PmergeMe::elementLess);

			int insert_idx = std::distance(winnerChain.begin(), insert_pos);
			// Como a lista de ganhadores vai virar a mainChain da funcao anterior
			// temos que setar qual era o seu indice na mainChain
			Element to_insert = {p_elem.value, p_elem.myOldIndex};
			winnerChain.insert(insert_pos, to_insert);

			std::cout << "    Inserido " << p_elem.value << " na posição " << insert_idx
				  << std::endl;

			// Atualiza a posicao dos ganhadores
			// só incrementa quem está à direita da posição inserida
			for (size_t j = 0; j < winnerCurrentPosMap.size(); ++j) {
				if (winnerCurrentPosMap[j] >= insert_idx)
					winnerCurrentPosMap[j]++;
			}
			printSequence("Mapa de indices:  ", winnerCurrentPosMap);
			current_idx--;
		}
		last_idxmap_used = group_end;
		if (last_idxmap_used >= pend.size() -1)
			break;
	}
}

bool PmergeMe::elementLess(const Element &elem, int val) { return elem.value < val; }

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


// ============================ DEQUE ====================================

// Função para ordenar utilizando um deque
void PmergeMe::sortDeque(const std::vector<int> &sequence) {
    std::cout << "=== INICIO sortDeque ===" << std::endl;

    printSequence("Before: ", sequence);

    // Criamos um deque de estrutura com os elementos
    std::deque<Element> elements;
    for (size_t i = 0; i < sequence.size(); ++i) {
        Element e = {sequence[i], static_cast<int>(i)};
        elements.push_back(e);
    }

    // Verificamos o tempo gasto pela função para ordenar um deque
    std::cout << "Chamando fordJohnson..." << std::endl;
    clock_t start = clock();
    fordJohnson(elements);
    clock_t end = clock();
    std::cout << "fordJohnson finalizado." << std::endl;

    std::deque<int> sorted_sequence;
    for (size_t i = 0; i < elements.size(); ++i)
        sorted_sequence.push_back(elements[i].value);

    printSequence("After:  ", sorted_sequence);

    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time to process a range of " << sorted_sequence.size()
          << " elements with std::deque: " << duration << " us" << std::endl;
    std::cout << "=== FIM sortDeque ===" << std::endl;
}

// Função que irá ordenar recursivamente os elementos (versão deque)
void PmergeMe::fordJohnson(std::deque<Element> &mainChain) {
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
    std::deque<Element> winnerChain;
    std::deque<PendElement> pend;

    splitIntoWinnersAndLosers(mainChain, winnerChain, pend);

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

    // Nesse momento a winnerChain já está ordenada
    // Pegar o primeiro elemento que sera incluido na lista de ganhadores
    // Ele é o par do menor ganhador
    int smallestWinnerOriginalPos = winnerChain[0].winnerIndex;
    Element firstPend = {pend[smallestWinnerOriginalPos].value,
                 pend[smallestWinnerOriginalPos].myOldIndex};

    // índice desse vetor será posicao do perdedor que dará a posicao atual do seu par ganhador
    // na lista dos ganhadores onde os perdedores tambem estarao sendo incluidos
    std::deque<int> winnerCurrentPosMap(pend.size());
    // indice do vetor é a posicao do ganhador que dará o posicao do seu par perdedor
    // esse vector sera estatico e sera usado apenas para pegarmos os perdedores na ordem de seus pares
    std::deque<int> loserIdxMap(pend.size());

    // Construir o MAPA DE ÍNDICES
    buildIndexMaps(winnerChain, pend, winnerCurrentPosMap, loserIdxMap);

    std::cout << "ETAPA 4: Inserindo elementos de pend em winnerChain..." << std::endl;
    // 4. Inserir os elementos da `pend` na `winnerChain` (lógica inalterada)
    winnerChain.insert(winnerChain.begin(), firstPend);
    std::cout << "Primeiro elemento de pend inserido no início: " << firstPend.value << std::endl;

    // Como um perdedor entrou na winnerChain na primeira posicao
    // precisamos atualizar a posicao de todos os ganhadores que estavam nessa lista
    for (size_t i = 0; i < winnerCurrentPosMap.size(); ++i)
        winnerCurrentPosMap[i]++;

    printSequence("Mapa de indices:  ", winnerCurrentPosMap);

    insertPendingElements(winnerChain, pend, winnerCurrentPosMap, loserIdxMap);

    if (hasStraggler) {
        std::cout << "ETAPA 5: Inserindo straggler..." << std::endl;
        std::deque<Element>::iterator insert_pos = std::lower_bound(
            winnerChain.begin(), winnerChain.end(), straggler.value, PmergeMe::elementLess);
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

void PmergeMe::buildIndexMaps(std::deque<Element> &winnerChain, std::deque<PendElement> &pend,
                  std::deque<int> &winnerCurrentPosMap, std::deque<int> &loserIdxMap) {

    for (size_t i = 0; i < winnerChain.size(); ++i) {
        // winnerChain[i].winnerIndex possui a posição ANTES da ordenação
        int winnerPositionBeforeSorting = winnerChain[i].winnerIndex;

        // o indice do vetor é posicao do perdedor na pend e o i informa onde seu par ganhador está
        winnerCurrentPosMap[winnerPositionBeforeSorting] = i;

        // loserIdxMap[i] diz qual é o índice do perdedor associado ao ganhador na posicao i
        // pendMap[i] diz qual é o índice do perdedor (em `pend`) associado ao ganhador na posicao `i` da winnerChain ordenada
        // ou seja, conseguimos "ordenar" os perdedores de acordo com os seus pares
        loserIdxMap[i] = winnerPositionBeforeSorting;

        // Como ja tenho a relacao de cada perdedor com o ganhador por meio do map,
        // ja posso setar o index do ganhador para o index que ele possuia na mainChain
        winnerChain[i].winnerIndex = pend[winnerPositionBeforeSorting].partnerOldIndex;
    }
}

// Função para criar pares e separar em ganhadores e perdedores (versão deque)
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

        // Na prática a mainChain acaba sendo o conjunto dos ganhadores da rodada anterior
        // Quando separamos a mainChain precisamos guardar qual era a posicao dos elementos nela
        // Essa informação será guardada pelo elemento perdedor
        int partnerOldIndex = winner.winnerIndex;
        // Os ganhadores vao levar sua posicao na lista de ganhadores,
        // para que possamos saber qual era sua posicao antes de ser ordenado
        winner.winnerIndex = winnerChain.size();
        winnerChain.push_back(winner);

        PendElement p = {loser.value, loser.winnerIndex, partnerOldIndex};
        pend.push_back(p);
    }
}

// Função para inserir perdedores na winnerChain usando sequência de Jacobsthal (versão deque)
void PmergeMe::insertPendingElements(std::deque<Element> &winnerChain, std::deque<PendElement> &pend,
                     std::deque<int> &winnerCurrentPosMap, std::deque<int> &loserIdxMap) {

    // O algoritmo utiliza a diferença do numeros da sequencia de Jabobstha
    // para definir a ordem de inserção dos perdedores e o grupos
    std::vector<int> jacobsthal_diffs = generateJacobsthalDiffs(pend.size());
    printSequence("jacobsthal: ", jacobsthal_diffs);
    // Como já inserimos o "primeiro" perdedor
    // O primeiro elemento (par do menor vencedor) é inserido primeiro, então começamos do índice 0.
    size_t last_idxmap_used = 0;

    std::cout << "Inserindo elementos restantes usando sequência Jacobsthal..." << std::endl;
    // Começamos do segundo grupo de Jacobsthal (i=1), pois o primeiro (tamanho 1) já foi inserido.
    for (size_t i = 1; i < jacobsthal_diffs.size(); ++i) {
        // Define o grupo a ser inserido que vai de group_end ou tamanho do pend até last_idxmap_used
        size_t group_end = last_idxmap_used + jacobsthal_diffs[i];
        size_t current_idx = std::min(group_end, pend.size() - 1);

        std::cout << "  Grupo Jacobsthal " << i << ": processando de " << current_idx << " até "
              << (last_idxmap_used + 1) << std::endl;
        std::cout << "  indice nos perdedores: " << loserIdxMap[current_idx] << std::endl;

        // A inserção dos grupos se dá na ordem decrescente
        while (current_idx > last_idxmap_used) {
            int loserPosInPend = loserIdxMap[current_idx];
            PendElement &p_elem = pend[loserPosInPend];

            // O limite da busca é a posição atual do par vencedor.
            int search_limit = winnerCurrentPosMap[loserPosInPend];

            std::deque<Element>::iterator insert_pos =
                std::lower_bound(winnerChain.begin(), winnerChain.begin() + search_limit + 1,
                         p_elem.value, PmergeMe::elementLess);

            int insert_idx = std::distance(winnerChain.begin(), insert_pos);
            // Como a lista de ganhadores vai virar a mainChain da funcao anterior
            // temos que setar qual era o seu indice na mainChain
            Element to_insert = {p_elem.value, p_elem.myOldIndex};
            winnerChain.insert(insert_pos, to_insert);

            std::cout << "    Inserido " << p_elem.value << " na posição " << insert_idx
                  << std::endl;

            // Atualiza a posicao dos ganhadores
            // só incrementa quem está à direita da posição inserida
            for (size_t j = 0; j < winnerCurrentPosMap.size(); ++j) {
                if (winnerCurrentPosMap[j] >= insert_idx)
                    winnerCurrentPosMap[j]++;
            }
            printSequence("Mapa de indices:  ", winnerCurrentPosMap);
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