#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sys/time.h> // Para gettimeofday


// Estrutura para os elementos pendentes ("perdedores")
struct PendElementInfo {
    int value;
    int original_partner_index; // Índice do seu "parceiro" na mainChain ANTES da recursão
};

// Estrutura para os elementos da cadeia principal ("vencedores")
// Guarda o valor e o seu índice original para reconstruir o mapa de índices sem comparações.
struct MainChainElement {
    int value;
    int original_index;
};


class PmergeMe {
public:

	// Métodos públicos para orquestrar a ordenação e exibição
	static void sortVector(int argc, char **argv);
	static void sortDeque(int argc, char **argv);

private:
	// Construtor padrão e de cópia privados para seguir a forma canónica (se necessário)
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	// --- Membros de Dados ---

	// Função para calcular o k-ésimo número de Jacobsthal
	static int jacobsthal(int k);

	// A função recursiva principal para o std::vector
	static void mergeInsertSortRecursive(std::vector<int>& vec);
	// A função recursiva principal para o std::vector
	static void mergeInsertSortRecursive(std::deque<int>& deq);
};