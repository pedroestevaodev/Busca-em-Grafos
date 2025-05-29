#include "busca_grafos.h"       // Inclusão do cabeçalho de busca em grafos
#include "definicoes_grafos.h"  // Inclusão do cabeçalho de definições de grafos
#include <iostream>             // Inclusão para std::cout, std::cerr, std::endl
#include <queue>                // Inclusão para std::priority_queue
#include <set>                  // Inclusão para std::set, usado para armazenar nós visitados
#include <string>               // Inclusão para poder usar strings

// Implementação do método bfs_g1 que executa uma Busca em Largura (BFS) no grafo G1
void bfs_g1(const std::string& inicio) {
    // Verificamos se o grafo G1 está vazio antes de iniciar a busca
    if (lista_adj_g1.empty()) {
        // Se o grafo G1 está vazio, mostramos uma mensagem de erro e retornamos
        std::cerr << "ERRO: O grafo G1 esta vazio." << std::endl;
        // Retornamos para não continuar com o processamento
        return;
    }
    // Verificamos se o nó inicial existe no grafo G1
    if (lista_adj_g1.find(inicio) == lista_adj_g1.end()) {
        // Se o nó inicial não foi encontrado, mostramos uma mensagem de erro e retornamos
        std::cerr << "ERRO: No inicial '" << inicio << "' nao encontrado em G1." << std::endl;
        // Retornamos para não continuar com o processamento
        return;
    }

    // Inicializamos um conjunto para armazenar os nós visitados e uma fila para a BFS
    // O conjunto nos_visitados evita que nós sejam visitados mais de uma vez, prevenindo ciclos
    std::set<std::string> nos_visitados;
    // A fila nos permite explorar os nós em ordem de descoberta, seguindo a lógica da BFS
    std::queue<std::string> fila_nos;

    // Adicionamos o nó inicial à fila e ao conjunto de nós visitados
    fila_nos.push(inicio);
    // O nó inicial é adicionado ao conjunto de nós visitados para evitar reprocessamento
    nos_visitados.insert(inicio);

    // Iniciamos a busca em largura (BFS) a partir do nó inicial
    // Exibimos uma mensagem informando o início da BFS e o nó inicial
    // A ordem de visitação dos nós será exibida na tela
    std::cout << "Iniciando Busca em Largura (BFS) a partir de '" << inicio << "':" << std::endl;
    // Exibimos a ordem de visitação dos nós na tela
    std::cout << "Nos visitados na ordem: ";
    // Variável para controlar a formatação da saída, para não imprimir " -> " antes do primeiro nó
    // A variável primeiro_no_seq é usada para controlar a formatação da saída, evitando imprimir " -> " antes do primeiro nó
    bool primeiro_no_seq = true;

    // Enquanto houver nós na fila, continuamos a explorar o grafo
    while (!fila_nos.empty()) {
        // Pegamos o nó atual da frente da fila
        std::string no_atual = fila_nos.front();
        // Removemos o nó atual da fila para processá-lo
        fila_nos.pop();

        // Adicionamos o nó atual à lista de nós visitados
        if (!primeiro_no_seq) {
            // Se não for o primeiro nó, imprimimos " -> " antes do nó atual
            std::cout << " -> ";
        }
        // Imprimimos o nó atual na saída padrão
        std::cout << no_atual;
        // Atualizamos a variável primeiro_no_seq para false, pois já processamos o primeiro nó
        primeiro_no_seq = false;

        // Exibimos uma mensagem informando que estamos processando o nó atual
        std::cout << std::endl << "  Processando '" << no_atual << "': ";
        // Variável para controlar se algum vizinho foi descoberto
        // A variável primeiro_vizinho_descoberto é usada para controlar a formatação da saída, evitando imprimir " -> " antes do primeiro vizinho
        bool primeiro_vizinho_descoberto = true;
        
        // Verificamos se o nó atual tem vizinhos na lista de adjacência do grafo G1
        if (lista_adj_g1.count(no_atual)) {
            // Iteramos sobre cada vizinho do nó atual
            for (const auto& vizinho : lista_adj_g1[no_atual]) {
                // Verificamos se o vizinho já foi visitado
                // Utilizamos a precedência de visitação de acordo com a ordem lexicográfica. [cite: 6]
                if (nos_visitados.find(vizinho) == nos_visitados.end()) { // Se não visitado
                    // Se o vizinho não foi visitado, adicionamos ele à fila e ao conjunto de nós visitados
                    nos_visitados.insert(vizinho);
                    // Adicionamos o vizinho à fila para processamento futuro
                    fila_nos.push(vizinho);
                    // Exibimos o vizinho descoberto na saída padrão
                    if (!primeiro_vizinho_descoberto) {
                        std::cout << ", ";
                    }
                    // Imprimimos o vizinho descoberto
                    std::cout << no_atual << " -> " << vizinho;
                    // Atualizamos a variável primeiro_vizinho_descoberto para false, pois já descobrimos um vizinho
                    primeiro_vizinho_descoberto = false;
                }
            }
        }

        // Se nenhum novo vizinho foi descoberto, informamos ao usuário
        // A variável primeiro_vizinho_descoberto controla se algum vizinho foi descoberto
        if (primeiro_vizinho_descoberto) {
            // Se nenhum vizinho foi descoberto, imprimimos uma mensagem informando isso
            std::cout << "Nenhum novo vizinho descoberto." << std::endl;
        } else {
            // Se vizinhos foram descobertos, finalizamos a linha de saída com um ponto final
            std::cout << std::endl;
        }
    }
    // Após processar todos os nós, exibimos uma mensagem informando que a BFS foi concluída
    // A BFS foi concluída, então imprimimos uma mensagem de conclusão
    std::cout << std::endl << "BFS concluida." << std::endl;
}

// Implementação do método dfs_util_g2 que executa uma Busca em Profundidade (DFS) no grafo G2
void dfs_util_g2(const std::string& no_atual, std::set<std::string>& nos_visitados, bool* primeiro_no_saida) {
    // Adicionamos o nó atual ao conjunto de nós visitados
    nos_visitados.insert(no_atual);

    // Exibimos o nó atual na saída padrão, formatando a saída para não imprimir " -> " antes do primeiro nó
    if (!(*primeiro_no_saida)) {
        std::cout << " -> ";
    }
    // Imprimimos o nó atual na saída padrão
    std::cout << no_atual;
    // Atualizamos a variável primeiro_no_saida para false, pois já processamos o primeiro nó
    // A variável primeiro_no_saida é usada para controlar a formatação da saída, evitando imprimir " -> " antes do primeiro nó
    *primeiro_no_saida = false;

    // Exibimos uma mensagem informando que estamos processando o nó atual
    if (lista_adj_g2.count(no_atual)) {
        // Iteramos sobre cada vizinho do nó atual na lista de adjacência do grafo G2
        for (const auto& vizinho : lista_adj_g2[no_atual]) {
            // Verificamos se o vizinho já foi visitado
            // Utilizamos a precedência de visitação de acordo com a ordem lexicográfica. [cite: 6]
            if (nos_visitados.find(vizinho) == nos_visitados.end()) {
                // Se o vizinho não foi visitado, chamamos recursivamente a função dfs_util_g2
                dfs_util_g2(vizinho, nos_visitados, primeiro_no_saida);
            }
        }
    }
}

// Implementação do método dfs_g2 que executa uma Busca em Profundidade (DFS) no grafo G2
void dfs_g2(const std::string& inicio) {
    // Verificamos se o grafo G2 está vazio antes de iniciar a busca
    if (lista_adj_g2.empty()) {
        // Se o grafo G2 está vazio, mostramos uma mensagem de erro e retornamos
        std::cerr << "ERRO: O grafo G2 esta vazio." << std::endl;
        // Retornamos para não continuar com o processamento
        return;
    }
    // Verificamos se o nó inicial existe no grafo G2
    if (lista_adj_g2.find(inicio) == lista_adj_g2.end()) {
        // Se o nó inicial não foi encontrado, mostramos uma mensagem de erro e retornamos
        std::cerr << "ERRO: No inicial '" << inicio << "' nao encontrado em G2." << std::endl;
        // Retornamos para não continuar com o processamento
        return;
    }

    // Inicializamos um conjunto para armazenar os nós visitados
    std::set<std::string> nos_visitados;
    // A variável primeiro_no_saida é usada para controlar a formatação da saída, evitando imprimir " -> " antes do primeiro nó
    bool primeiro_no_saida = true;

    // Exibimos uma mensagem informando o início da DFS e o nó inicial
    std::cout << "Ordem de visitacao (DFS) a partir de '" << inicio << "': ";
    // Chamamos a função auxiliar dfs_util_g2 para iniciar a busca em profundidade
    dfs_util_g2(inicio, nos_visitados, &primeiro_no_saida);
    // Após processar todos os nós, exibimos uma mensagem informando que a DFS foi concluída
    std::cout << std::endl << "DFS concluida." << std::endl;
}