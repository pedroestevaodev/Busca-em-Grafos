// GRUPO 19:
// PEDRO AUGUSTO DE OLIVEIRA SOUZA - 2174638
// PEDRO ESTEVÃO PAULISTA DE MELLO - 2173562
// SARAH BEIRIGO – 2173107

#include "dijkstra.h"           // Inclusão do cabeçalho de Dijkstra
#include "definicoes_grafos.h"  // Inclusão do cabeçalho de definições de grafos
#include <iostream>             // Inclusão para std::cout, std::cerr, std::endl
#include <vector>               // Inclusão para poder usar vetores
#include <map>                  // Inclusão para poder usar mapas
#include <queue>                // Inclusão para std::priority_queue
#include <limits>               // Inclusão para std::numeric_limits
#include <algorithm>            // Inclusão para usar o método std::sort (ordenação)

// Implementação do método calcular_dijkstra_g3 que calcula o caminho mínimo usando o algoritmo de Dijkstra no grafo G3
void calcular_dijkstra_g3(const std::string& inicio, const std::string& fim) {
    // Verificamos se o grafo G3 está vazio ou se os nós de início e fim existem
    if (lista_adj_g3.empty()) {
        // Se o grafo G3 está vazio, mostramos uma mensagem de erro
        std::cerr << "ERRO: O grafo G3 esta vazio." << std::endl;
        // E retornamos para não continuar com o processamento
        return;
    }
    // Verificamos se o nó inicial e o nó final existem no grafo G3
    if (lista_adj_g3.find(inicio) == lista_adj_g3.end()) {
        // Se o nó inicial não foi encontrado, mostramos uma mensagem de erro
        std::cerr << "ERRO: No inicial '" << inicio << "' nao encontrado em G3." << std::endl;
        // E retornamos para não continuar com o processamento
        return;
    }
    // Verificamos se o nó final existe no grafo G3
    if (lista_adj_g3.find(fim) == lista_adj_g3.end()) {
        // Se o nó final não foi encontrado, mostramos uma mensagem de erro
        std::cerr << "ERRO: No final '" << fim << "' nao encontrado em G3." << std::endl;
        // E retornamos para não continuar com o processamento
        return;
    }

    // Inicializamos as estruturas de dados necessárias para o algoritmo de Dijkstra
    // Usamos um mapa para armazenar as distâncias mínimas de cada nó a partir do nó inicial
    std::map<std::string, int> distancia;
    // Usamos um mapa para armazenar o nó anterior de cada nó no caminho mais curto
    std::map<std::string, std::string> anterior;
    // Usamos uma fila de prioridade para escolher o próximo nó a ser processado com base na menor distância
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> fila_prioridade;

    // Inicializamos as distâncias de todos os nós como infinito (ou seja, não visitados)
    for (const auto& par_no_adj : lista_adj_g3) {
        // Para cada nó no grafo G3, definimos a distância inicial como infinito
        distancia[par_no_adj.first] = std::numeric_limits<int>::max();
        // E o nó anterior como vazio (ou seja, não tem predecessor)
        anterior[par_no_adj.first] = "";
    }

    // A distância do nó inicial para ele mesmo é zero, pois não há custo para ficar no mesmo nó
    distancia[inicio] = 0;
    // Adicionamos o nó inicial na fila de prioridade com distância zero
    fila_prioridade.emplace(0, inicio);

    // Enquanto houver nós na fila de prioridade, continuamos o processamento
    while (!fila_prioridade.empty()) {
        // Pegamos o nó com a menor distância da fila de prioridade
        int distancia_atual = fila_prioridade.top().first;
        // O nome do nó atual é o segundo elemento do par na fila de prioridade
        std::string no_atual = fila_prioridade.top().second;
        // Removemos o nó atual da fila de prioridade
        fila_prioridade.pop();

        // Se já encontramos um caminho mais curto para este nó, ignoramos
        if (distancia_atual > distancia[no_atual]) {
            // Pulamos para a próxima iteração do loop
            continue;
        }

        // Iteramos sobre os vizinhos do nó atual
        if (lista_adj_g3.count(no_atual)) { // Verificamos se o nó atual existe no grafo
            // Para cada vizinho do nó atual, verificamos o peso da aresta
            for (const auto& par_vizinho_peso : lista_adj_g3[no_atual]) {
                // Extraímos o nome do vizinho e o peso da aresta
                const std::string& nome_vizinho = par_vizinho_peso.first;
                // O peso da aresta é o segundo elemento do par
                int peso_aresta = par_vizinho_peso.second;

                // Calculamos a nova distância para o vizinho
                int nova_distancia = distancia[no_atual] + peso_aresta;

                // Se encontramos um caminho mais curto para o vizinho
                if (nova_distancia < distancia[nome_vizinho]) {
                    // Atualizamos a distância do vizinho
                    distancia[nome_vizinho] = nova_distancia;
                    // Atualizamos o nó anterior do vizinho para o nó atual
                    anterior[nome_vizinho] = no_atual;
                    // Adicionamos o vizinho na fila de prioridade com a nova distância
                    fila_prioridade.emplace(nova_distancia, nome_vizinho);
                }
            }
        }
    }

    // Após processar todos os nós, verificamos se encontramos um caminho para o nó final
    if (distancia[fim] == std::numeric_limits<int>::max()) {
        // Se a distância para o nó final ainda for infinito, significa que não há caminho possível
        // Então, mostramos uma mensagem informando que não há caminho possível
        std::cout << "Resultado: Nao ha caminho possivel de '" << inicio << "' para '" << fim << "' no grafo G3." << std::endl;
        // E retornamos para não continuar com o processamento
        return;
    }

    // Se chegamos aqui, significa que encontramos um caminho do nó inicial ao nó final
    std::cout << "Resultado: O custo minimo para ir de '" << inicio << "' a '" << fim << "' e: " << distancia[fim] << std::endl;

    // Agora, vamos reconstruir o caminho mínimo encontrado
    // Usamos um vetor para armazenar os nós do caminho mínimo
    std::vector<std::string> caminho_nos;
    // Começamos do nó final e vamos retrocedendo até o nó inicial usando o mapa de predecessores
    std::string no_iterador = fim;
    // Enquanto o nó iterador não for vazio e não for o nó inicial, continuamos retrocedendo
    while (no_iterador != "" && no_iterador != inicio) {
        // Adicionamos o nó iterador ao vetor de caminho
        caminho_nos.push_back(no_iterador);
        // Retrocedemos para o nó anterior no caminho
        no_iterador = anterior[no_iterador];
    }
    // Adicionamos o nó inicial ao vetor de caminho
    caminho_nos.push_back(inicio);

    // Invertendo o vetor de caminho para ter a ordem correta do início ao fim
    std::reverse(caminho_nos.begin(), caminho_nos.end());

    // Exibimos o caminho mínimo encontrado
    std::cout << "Caminho minimo encontrado (nos): ";
    // Imprimimos os nós do caminho em ordem
    for (size_t i = 0; i < caminho_nos.size(); ++i) {
        // Exibimos cada nó do caminho, separando-os por " -> "
        std::cout << caminho_nos[i] << (i == caminho_nos.size() - 1 ? "" : " -> ");
    }
    // Finalizamos a linha de saída
    std::cout << std::endl;

    // Exibimos as arestas correspondentes ao caminho encontrado
    std::cout << "Arestas correspondentes ao caminho: ";
    // Imprimimos as arestas do caminho, separando-as por vírgulas
    for (size_t i = 0; i < caminho_nos.size() - 1; ++i) {
        // Exibimos cada aresta do caminho, no formato "no1-no2"
        std::cout << caminho_nos[i] << "-" << caminho_nos[i+1] << (i == caminho_nos.size() - 2 ? "" : ", ");
    }
    // Finalizamos a linha de saída
    std::cout << std::endl;
}
