#include "leitura_grafos.h"     // Para as funcoes de leitura de grafo
#include "busca_grafos.h" // Para as funcoes de busca (BFS/DFS)
#include "dijkstra.h"     // Para o algoritmo de Dijkstra
#include <iostream>       // Para cout e cerr

using namespace std; 

int main() {
    // Otimizacao de I/O: Desvincula C++ streams do C standard I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "=======================================" << endl;
    cout << "      INICIANDO PROCESSAMENTO DE GRAFOS" << endl;
    cout << "=======================================" << endl << endl;

    // Leitura dos grafos a partir dos arquivos.
    cout << "---------------------------------------" << endl;
    cout << "  FASE DE LEITURA DOS ARQUIVOS DE GRAFO" << endl;
    cout << "---------------------------------------" << endl;

    if (!ler_grafo_g1("g1.txt")) {
        cerr << "ERRO FATAL: Falha ao ler o arquivo g1.txt." << endl;
        return 1;
    }
    cout << "-> Grafo G1 (nao direcionado, nao ponderado) lido com sucesso de 'g1.txt'." << endl;

    if (!ler_grafo_g2("g2.txt")) {
        cerr << "ERRO FATAL: Falha ao ler o arquivo g2.txt." << endl;
        return 1;
    }
    cout << "-> Grafo G2 (direcionado) lido com sucesso de 'g2.txt'." << endl;

    if (!ler_grafo_g3("g3.txt")) {
        cerr << "ERRO FATAL: Falha ao ler o arquivo g3.txt." << endl;
        return 1;
    }
    cout << "-> Grafo G3 (nao direcionado, ponderado) lido com sucesso de 'g3.txt'." << endl;
    cout << "---------------------------------------" << endl << endl;


    // Execucao das operacoes nos grafos.
    cout << "=======================================" << endl;
    cout << "     INICIANDO OPERACOES NOS GRAFOS" << endl;
    cout << "=======================================" << endl << endl;

    // --- BFS em G1 ---
    cout << "---------------------------------------" << endl;
    cout << "  BUSCA EM LARGURA (BFS) NO GRAFO G1" << endl;
    cout << "  (A partir do no inicial 'b')" << endl;
    cout << "---------------------------------------" << endl;
    bfs_g1("b");
    cout << "---------------------------------------" << endl << endl;


    // --- DFS em G2 ---
    cout << "---------------------------------------" << endl;
    cout << "  BUSCA EM PROFUNDIDADE (DFS) NO GRAFO G2" << endl;
    cout << "  (A partir do no inicial 'a')" << endl;
    cout << "---------------------------------------" << endl;
    dfs_g2("a");
    cout << "---------------------------------------" << endl << endl;


    // --- Dijkstra em G3 ---
    cout << "---------------------------------------" << endl;
    cout << "  ALGORITMO DE DIJKSTRA NO GRAFO G3" << endl;
    cout << "  (Caminho minimo de 'x' para 't')" << endl;
    cout << "---------------------------------------" << endl;
    calcular_dijkstra_g3("x", "t");
    cout << "---------------------------------------" << endl << endl;

    cout << "=======================================" << endl;
    cout << "  TODAS AS OPERACOES CONCLUIDAS COM SUCESSO" << endl;
    cout << "=======================================" << endl << endl;

    return 0;
}