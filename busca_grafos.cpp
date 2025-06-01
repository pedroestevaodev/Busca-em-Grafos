// GRUPO 19:
// PEDRO AUGUSTO DE OLIVEIRA SOUZA - 2174638
// PEDRO ESTEVÃO PAULISTA DE MELLO - 2173562
// SARAH BEIRIGO – 2173107

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
    // Inicializamos um vetor para armazenar a ordem de visitação dos nós
    std::vector<std::string> ordem_visitacao;

    // Adicionamos o nó inicial à fila e ao conjunto de nós visitados
    fila_nos.push(inicio);
    // O nó inicial é adicionado ao conjunto de nós visitados para evitar reprocessamento
    nos_visitados.insert(inicio);

    // Iniciamos a busca em largura (BFS) a partir do nó inicial
    // Exibimos uma mensagem informando o início da BFS e o nó inicial
    // A ordem de visitação dos nós será exibida na tela
    std::cout << "Iniciando Busca em Largura (BFS) a partir de '" << inicio << "':" << std::endl;
    
    // Enquanto houver nós na fila, continuamos a explorar o grafo
    while (!fila_nos.empty()) { // Continuamos enquanto houver nós na fila para visitar.
        // Pegamos o nó atual da frente da fila.
        std::string no_atual = fila_nos.front();
        // Exibimos o nó atual que está sendo processado.
        fila_nos.pop();

        // Adicionamos o nó atual à lista de ordem de visitação.
        // Isso nos permite manter o registro da ordem em que os nós foram visitados.
        ordem_visitacao.push_back(no_atual);

        // Verificamos se o nó atual realmente existe no mapa de adjacência antes de tentar ver seus vizinhos.
        if (lista_adj_g1.count(no_atual)) {
            // Percorremos todos os vizinhos do nó atual.
            // Isso nos permite explorar todos os nós conectados ao nó atual.
            for (const auto& vizinho : lista_adj_g1[no_atual]) {
                // Usamos a ordem alfabética (lexicográfica) para decidir a precedência de visitação.
                if (nos_visitados.find(vizinho) == nos_visitados.end()) { // Se o vizinho ainda não foi visitado...
                    nos_visitados.insert(vizinho); // ...marca o vizinho como visitado.
                    fila_nos.push(vizinho);        // ...coloca o vizinho na fila para ser visitado depois.
                }
            }
        }
    }

    // Exibe a ordem final de visitação, similar à DFS.
    std::cout << "Ordem de visitacao (BFS) a partir de '" << inicio << "': ";
    // Percorremos a lista de nós visitados e imprimimos a ordem de visitação.
    // Usamos um loop para percorrer cada nó na ordem de visitação.
    for (size_t i = 0; i < ordem_visitacao.size(); ++i) {
        // Imprimimos o nó atual na ordem de visitação.
        // Usamos um operador ternário para formatar a saída, adicionando uma seta entre os nós.
        std::cout << ordem_visitacao[i] << (i == ordem_visitacao.size() - 1 ? "" : " -> ");
    }
    // Após processar todos os nós, exibimos uma mensagem informando que a BFS foi concluída
    // A mensagem de conclusão indica que a busca em largura foi finalizada com sucesso.
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