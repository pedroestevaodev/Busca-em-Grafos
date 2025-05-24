#include "busca_grafos.h"
#include "definicoes_grafos.h"
#include <iostream>
#include <queue>
#include <set>

using namespace std;

void bfs_g1(const string& inicio) {
    if (lista_adj_g1.empty()) {
        cerr << "ERRO: O grafo G1 esta vazio." << endl;
        return;
    }
    if (!lista_adj_g1.count(inicio)) {
        cerr << "ERRO: No inicial '" << inicio << "' nao encontrado em G1." << endl;
        return;
    }

    set<string> nos_visitados;
    queue<string> fila_nos;

    fila_nos.push(inicio);
    nos_visitados.insert(inicio);

    cout << "Iniciando Busca em Largura (BFS) a partir de '" << inicio << "':" << endl;
    cout << "Nós visitados na ordem: ";
    bool primeiro_no_seq = true; // Para a sequência linear de nós visitados

    while (!fila_nos.empty()) {
        string no_atual = fila_nos.front();
        fila_nos.pop();

        // Imprime o nó na sequência linear de visitação
        if (!primeiro_no_seq) {
            cout << " -> ";
        }
        cout << no_atual;
        primeiro_no_seq = false;

        // Imprime a exploração dos vizinhos a partir do nó atual
        cout << endl << "  Processando '" << no_atual << "': ";
        bool primeiro_vizinho_descoberto = true;
        for (const auto& vizinho : lista_adj_g1[no_atual]) {
            if (!nos_visitados.count(vizinho)) {
                nos_visitados.insert(vizinho);
                fila_nos.push(vizinho);
                if (!primeiro_vizinho_descoberto) {
                    cout << ", ";
                }
                cout << no_atual << " -> " << vizinho;
                primeiro_vizinho_descoberto = false;
            }
        }
        if (primeiro_vizinho_descoberto) { // Se nenhum novo vizinho foi descoberto
            cout << "Nenhum novo vizinho descoberto." << endl;
        } else {
            cout << endl;
        }
    }
    cout << endl << "BFS concluida." << endl;
}

// As funções dfs_util_g2 e dfs_g2 permanecem inalteradas
void dfs_util_g2(const string& no_atual, set<string>& nos_visitados, bool* primeiro_no_saida) {
    nos_visitados.insert(no_atual);

    if (!(*primeiro_no_saida)) {
        cout << " -> ";
    }
    cout << no_atual;
    *primeiro_no_saida = false;

    for (const auto& vizinho : lista_adj_g2[no_atual]) {
        if (!nos_visitados.count(vizinho)) {
            dfs_util_g2(vizinho, nos_visitados, primeiro_no_saida);
        }
    }
}

void dfs_g2(const string& inicio) {
    if (lista_adj_g2.empty()) {
        cerr << "ERRO: O grafo G2 esta vazio." << endl;
        return;
    }
    if (!lista_adj_g2.count(inicio)) {
        cerr << "ERRO: No inicial '" << inicio << "' nao encontrado em G2." << endl;
        return;
    }

    set<string> nos_visitados;
    bool primeiro_no_saida = true;

    cout << "Ordem de visitacao (DFS) a partir de '" << inicio << "': ";
    dfs_util_g2(inicio, nos_visitados, &primeiro_no_saida);
    cout << endl;
}