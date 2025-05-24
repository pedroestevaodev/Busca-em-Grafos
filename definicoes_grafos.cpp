#include "definicoes_grafos.h"

using namespace std;

// Declaracoes das listas de adjacencia para os tres grafos.
// lista_adj_g1: Grafo não direcionado, não ponderado.
map<string, vector<string>> lista_adj_g1;
// lista_adj_g2: Grafo direcionado.
map<string, vector<string>> lista_adj_g2;
// lista_adj_g3: Grafo não direcionado, ponderado.
map<string, vector<pair<string, int>>> lista_adj_g3;