#ifndef LEITURA_GRAFOS_H
#define LEITURA_GRAFOS_H

#include <string>

using namespace std;

///  Lê o grafo G1 (não direcionado e não ponderado) de um arquivo
bool ler_grafo_g1(const string& nome_arquivo);

/// Lê o grafo G2 (direcionado) de um arquivo
bool ler_grafo_g2(const string& nome_arquivo);

/// Lê o grafo G3 (não direcionado e ponderado) de um arquivo
bool ler_grafo_g3(const string& nome_arquivo);

#endif