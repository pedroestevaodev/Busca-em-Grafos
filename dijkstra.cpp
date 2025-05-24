#include "dijkstra.h"
#include "definicoes_grafos.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

void calcular_dijkstra_g3(const string& inicio, const string& fim) {
    if (lista_adj_g3.empty()) {
        cerr << "ERRO: O grafo G3 esta vazio." << endl;
        return;
    }
    if (!lista_adj_g3.count(inicio)) {
        cerr << "ERRO: No inicial '" << inicio << "' nao encontrado em G3." << endl;
        return;
    }
    if (!lista_adj_g3.count(fim)) {
        cerr << "ERRO: No final '" << fim << "' nao encontrado em G3." << endl;
        return;
    }

    map<string, int> distancia;
    map<string, string> anterior;
    using ParNoDistancia = pair<int, string>;
    priority_queue<ParNoDistancia, vector<ParNoDistancia>, greater<>> fila_prioridade;

    for (const auto& par_no_adj : lista_adj_g3) {
        distancia[par_no_adj.first] = numeric_limits<int>::max();
    }

    distancia[inicio] = 0;
    fila_prioridade.emplace(0, inicio);

    while (!fila_prioridade.empty()) {
        auto [distancia_atual, no_atual] = fila_prioridade.top();
        fila_prioridade.pop();

        if (distancia_atual > distancia[no_atual]) {
            continue;
        }

        for (const auto& par_vizinho_peso : lista_adj_g3[no_atual]) {
            const string& nome_vizinho = par_vizinho_peso.first;
            int peso_aresta = par_vizinho_peso.second;

            int nova_distancia = distancia[no_atual] + peso_aresta;

            if (nova_distancia < distancia[nome_vizinho]) {
                distancia[nome_vizinho] = nova_distancia;
                anterior[nome_vizinho] = no_atual;
                fila_prioridade.emplace(nova_distancia, nome_vizinho);
            }
        }
    }

    if (distancia[fim] == numeric_limits<int>::max()) {
        cout << "Resultado: Nao ha caminho possivel de '" << inicio << "' para '" << fim << "' no grafo G3." << endl;
        return;
    }

    cout << "Resultado: O custo minimo para ir de '" << inicio << "' a '" << fim << "' e: " << distancia[fim] << endl;

    vector<string> caminho;
    string no_iterador = fim;
    while (no_iterador != inicio && lista_adj_g3.count(no_iterador) && !anterior[no_iterador].empty()) {
        caminho.push_back(no_iterador);
        no_iterador = anterior[no_iterador];
    }
    caminho.push_back(inicio);

    reverse(caminho.begin(), caminho.end());

    cout << "Caminho minimo encontrado: ";
    for (size_t i = 0; i < caminho.size(); ++i) {
        if (i > 0) {
            cout << " -> ";
        }
        cout << caminho[i];
    }
    cout << endl;
}