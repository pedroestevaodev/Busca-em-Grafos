// GRUPO 19:
// PEDRO AUGUSTO DE OLIVEIRA SOUZA - 2174638
// PEDRO ESTEVÃO PAULISTA DE MELLO - 2173562
// SARAH BEIRIGO – 2173107

// Guardas de inclusão para evitar múltiplas inclusões do cabeçalho
#ifndef DEFINICOES_GRAFOS_H
#define DEFINICOES_GRAFOS_H

#include <string>  // Inclusão para poder usar strings
#include <vector>  // Inclusão para poder usar vetores
#include <map>     // Inclusão para poder usar mapas
#include <utility> // Inclusão para poder usar pares de valores

// Declarações externas das listas de adjacência
// Lista de adjacência para o grafo G1 (não direcionado, não ponderado)
extern std::map<std::string, std::vector<std::string>> lista_adj_g1;
// Lista de adjacência para o grafo G2 (direcionado)
extern std::map<std::string, std::vector<std::string>> lista_adj_g2;
// Lista de adjacência para o grafo G3 (não direcionado, ponderado)
extern std::map<std::string, std::vector<std::pair<std::string, int>>> lista_adj_g3;

#endif // Fim da guarda de inclusão
