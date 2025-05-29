// Inclusão do cabeçalho de definições de grafos
#include "definicoes_grafos.h" 

// Definições das listas de adjacência para os três grafos
// lista_adj_g1: Grafo não direcionado, não ponderado
std::map<std::string, std::vector<std::string>> lista_adj_g1;
// lista_adj_g2: Grafo direcionado
std::map<std::string, std::vector<std::string>> lista_adj_g2;
// lista_adj_g3: Grafo não direcionado, ponderado
std::map<std::string, std::vector<std::pair<std::string, int>>> lista_adj_g3;
