#include "leitura_grafos.h"   // Inclusão do cabeçalho de leitura de grafos
#include "busca_grafos.h"     // Inclusão do cabeçalho de busca em grafos
#include "dijkstra.h"         // Inclusão do cabeçalho de Dijkstra
#include <iostream>           // Inclusão para std::cout, std::cerr, std::endl

// Função principal do programa
int main() {
    // Configuração de entrada e saída para evitar sincronização com C
    // Isso melhora a performance ao ler e escrever dados, especialmente em grandes volumes
    std::ios_base::sync_with_stdio(false);
    // Desativa a sincronização entre C e C++ para melhorar a performance
    std::cin.tie(NULL);

    // Mensagem de início do processamento de grafos
    std::cout << "=============================================" << std::endl;
    std::cout << "      INICIANDO PROCESSAMENTO DE GRAFOS" << std::endl;
    std::cout << "=============================================" << std::endl << std::endl;

    // Fase de leitura dos arquivos de grafo
    // Exibe uma mensagem informando que estamos iniciando a leitura dos arquivos de grafo
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "  FASE DE LEITURA DOS ARQUIVOS DE GRAFO" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    // Tentativa de ler os arquivos de grafo
    if (!ler_grafo("g1.txt")) {
        // Se a leitura do arquivo g1.txt falhar, exibe uma mensagem de erro e encerra o programa
        std::cerr << "ERRO FATAL: Falha ao ler o arquivo g1.txt." << std::endl;
        return 1;
    }
    // Se a leitura do arquivo g1.txt for bem-sucedida, exibe uma mensagem de sucesso
    std::cout << "-> Grafo G1 (nao direcionado, nao ponderado) lido com sucesso de 'g1.txt'." << std::endl;

    // Tentativa de ler os arquivos de grafo
    if (!ler_grafo("g2.txt")) {
        // Se a leitura do arquivo g2.txt falhar, exibe uma mensagem de erro e encerra o programa
        std::cerr << "ERRO FATAL: Falha ao ler o arquivo g2.txt." << std::endl;
        return 1;
    }
    // Se a leitura do arquivo g2.txt for bem-sucedida, exibe uma mensagem de sucesso
    std::cout << "-> Grafo G2 (direcionado) lido com sucesso de 'g2.txt'." << std::endl;

    // Tentativa de ler os arquivos de grafo
    if (!ler_grafo("g3.txt")) {
        // Se a leitura do arquivo g3.txt falhar, exibe uma mensagem de erro e encerra o programa
        std::cerr << "ERRO FATAL: Falha ao ler o arquivo g3.txt." << std::endl;
        return 1;
    }
    // Se a leitura do arquivo g3.txt for bem-sucedida, exibe uma mensagem de sucesso
    std::cout << "-> Grafo G3 (nao direcionado, ponderado) lido com sucesso de 'g3.txt'." << std::endl;
    std::cout << "---------------------------------------" << std::endl << std::endl;


    // Mensagem de início das operações nos grafos
    std::cout << "========================================" << std::endl;
    std::cout << "     INICIANDO OPERACOES NOS GRAFOS" << std::endl;
    std::cout << "========================================" << std::endl << std::endl;

    // --- BFS em G1 ---
    // Exibe uma mensagem informando que estamos iniciando a Busca em Largura (BFS) no grafo G1
    // A BFS será iniciada a partir do nó inicial 'b'
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "  BUSCA EM LARGURA (BFS) NO GRAFO G1" << std::endl;
    std::cout << "  (A partir do no inicial 'b')" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    bfs_g1("b");
    std::cout << "---------------------------------------" << std::endl << std::endl;


    // --- DFS em G2 ---
    // Exibe uma mensagem informando que estamos iniciando a Busca em Profundidade (DFS) no grafo G2
    // A DFS será iniciada a partir do nó inicial 'a'
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "  BUSCA EM PROFUNDIDADE (DFS) NO GRAFO G2" << std::endl;
    std::cout << "  (A partir do no inicial 'a')" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    dfs_g2("a");
    std::cout << "-------------------------------------------" << std::endl << std::endl;


    // --- Dijkstra em G3 ---
    // Exibe uma mensagem informando que estamos iniciando o algoritmo de Dijkstra no grafo G3
    // O algoritmo será executado para encontrar o caminho mínimo do nó 'x' ao nó 't'
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "  ALGORITMO DE DIJKSTRA NO GRAFO G3" << std::endl;
    std::cout << "  (Caminho minimo de 'x' para 't')" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    calcular_dijkstra_g3("x", "t");
    std::cout << "---------------------------------------" << std::endl << std::endl;

    // Mensagem de conclusão de todas as operações
    std::cout << "=============================================" << std::endl;
    std::cout << "  TODAS AS OPERACOES CONCLUIDAS COM SUCESSO" << std::endl;
    std::cout << "=============================================" << std::endl << std::endl;

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
