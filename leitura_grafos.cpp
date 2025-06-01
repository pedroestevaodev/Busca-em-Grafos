// GRUPO 19:
// PEDRO AUGUSTO DE OLIVEIRA SOUZA - 2174638
// PEDRO ESTEVÃO PAULISTA DE MELLO - 2173562
// SARAH BEIRIGO – 2173107

#include "leitura_grafos.h"  // Inclusão do cabeçalho de leitura de grafos
#include <fstream>           // Inclusão para manipulação de arquivos
#include <sstream>           // Inclusão para manipulação de strings
#include <algorithm>         // Inclusão para usar o método std::sort (ordenação)
#include <iostream>          // Inclusão para std::cerr, std::cout, std::endl
#include <stdexcept>         // Inclusão para exceções std::invalid_argument e std::out_of_range

// Implementação do método ler_grafo que lê um grafo de um arquivo e preenche a lista de adjacência correspondente
bool ler_grafo(const std::string& nome_arquivo) {
    // Declaramos uma variável para abrir e ler o arquivo
    std::ifstream arquivo(nome_arquivo);

    // Verificamos se o arquivo conseguiu ser aberto
    if (!arquivo.is_open()) {
        // Se não abriu, mostramos uma mensagem de erro
        std::cerr << "Erro: Nao foi possivel abrir o arquivo: " << nome_arquivo << std::endl;
        // Retornamos false para indicar que algo deu errado
        return false;
    }

    // Declaramos uma string para guardar cada linha lida do arquivo
    std::string linha; 
    // Declaramos strings temporárias para guardar as partes da linha (nó de origem, nó de destino, e peso se houver)
    std::string no_u_str, no_v_str, peso_str; 
    // Declaramos uma variável inteira para armazenar o peso da aresta
    int peso; 

    // Limpamos as listas de adjacência antes de preencher, para garantir que não haja dados antigos
    if (nome_arquivo == "g1.txt") { // Se o arquivo for do G1...
        lista_adj_g1.clear();       // ...limpamos a lista de adjacência do G1
    } else if (nome_arquivo == "g2.txt") { // Se o arquivo for do G2...
        lista_adj_g2.clear();       // ...limpamos a lista de adjacência do G2
    } else if (nome_arquivo == "g3.txt") { // Se o arquivo for do G3...
        lista_adj_g3.clear();       // ...limpamos a lista de adjacência do G3
    } else { // Se o nome do arquivo não for nenhum dos esperados...
        // ...mostramos um erro
        std::cerr << "Erro: Nome de arquivo desconhecido para leitura de grafo: " << nome_arquivo << std::endl; 
        // Retornamos false
        return false; 
    }

    // Lemos o arquivo linha por linha
    // Usamos um loop que continua enquanto conseguirmos ler uma linha do arquivo
    while (std::getline(arquivo, linha)) {
        // Declaramos um stream de string para processar a linha lida
        std::istringstream iss(linha);

        // Caso o arquivo seja do G1, G2 ou G3, processamos a linha de acordo com o formato esperado
        if (nome_arquivo == "g1.txt") { // Se o arquivo for do G1...
            // Formato G1: U;V; (não direcionado, não ponderado)
            // Tentamos pegar as duas partes da linha separadas por ';'.
            if (!std::getline(iss, no_u_str, ';') || !std::getline(iss, no_v_str, ';')) {
                // Se a linha não tem o formato certo, avisamos o usuário e continuamos para a próxima linha
                std::cerr << "Aviso: Linha mal formatada (esperado U;V;) em " << nome_arquivo << ": " << linha << std::endl;
                continue;
            }
            // Adicionamos os nós na lista de adjacência do G1
            lista_adj_g1[no_u_str].push_back(no_v_str);
            // Como o G1 é não direcionado, também adicionamos o nó inverso
            lista_adj_g1[no_v_str].push_back(no_u_str);
        } else if (nome_arquivo == "g2.txt") { // Se o arquivo for do G2...
            // Formato G2: U;V; (direcionado)
            // Tentamos pegar as duas partes da linha separadas por ';'.
            if (!std::getline(iss, no_u_str, ';') || !std::getline(iss, no_v_str, ';')) {
                // Se a linha não tem o formato certo, avisamos o usuário e continuamos para a próxima linha
                std::cerr << "Aviso: Linha mal formatada (esperado U;V;) em " << nome_arquivo << ": " << linha << std::endl;
                continue;
            }
            // Adicionamos os nós na lista de adjacência do G2
            lista_adj_g2[no_u_str].push_back(no_v_str);
        } else if (nome_arquivo == "g3.txt") { // Se o arquivo for do G3...
            // Formato G3: U;V;W; (não direcionado, ponderado)
            // Tentamos pegar as três partes da linha separadas por ';'.
            if (!std::getline(iss, no_u_str, ';') || !std::getline(iss, no_v_str, ';') || !std::getline(iss, peso_str, ';')) {
                // Se a linha não tem o formato certo, avisamos o usuário e continuamos para a próxima linha
                std::cerr << "Aviso: Linha mal formatada (esperado U;V;W;) em " << nome_arquivo << ": " << linha << std::endl;
                continue;
            }
            // Tentamos converter o peso de string para inteiro
            try {
                // Converte a string do peso para um inteiro
                peso = std::stoi(peso_str);
            } catch (const std::invalid_argument& e) { // Se a conversão falhar, avisamos o usuário
                // Aviso de peso inválido ou não numérico
                std::cerr << "Aviso: Peso invalido '" << peso_str << "' em linha: " << linha << " do arquivo " << nome_arquivo << std::endl;
                // Continuamos para a próxima linha
                continue;
            } catch (const std::out_of_range& e) { // Se o peso estiver fora do intervalo de um int, avisamos o usuário
                // Aviso de peso fora do intervalo de int
                std::cerr << "Aviso: Peso fora do alcance int '" << peso_str << "' em linha: " << linha << " do arquivo " << nome_arquivo << std::endl;
                // Continuamos para a próxima linha
                continue;
            }
            // Adicionamos os nós e o peso na lista de adjacência do G3
            lista_adj_g3[no_u_str].emplace_back(no_v_str, peso);
            // Como o G3 é não direcionado, também adicionamos o nó inverso com o mesmo peso
            lista_adj_g3[no_v_str].emplace_back(no_u_str, peso);
        }
    }

    // Ordenamos as listas de adjacência para garantir a precedência lexicográfica
    if (nome_arquivo == "g1.txt") {
        // Para G1, ordenamos por nome do vizinho
        for (auto& par_no_vizinhos : lista_adj_g1) {
            std::sort(par_no_vizinhos.second.begin(), par_no_vizinhos.second.end());
        }
    } else if (nome_arquivo == "g2.txt") { // Para G2, ordenar por nome do vizinho
        // G2 é direcionado, mas ainda ordenamos os vizinhos para consistência
        for (auto& par_no_vizinhos : lista_adj_g2) {
            std::sort(par_no_vizinhos.second.begin(), par_no_vizinhos.second.end());
        }
    } else if (nome_arquivo == "g3.txt") { // Para G3, ordenar por nome do vizinho
        // G3 é não direcionado e ponderado, então ordenamos os vizinhos por nome
        for (auto& par_no_vizinhos : lista_adj_g3) {
            // Para G3, ordenamos por nome do vizinho
            std::sort(par_no_vizinhos.second.begin(), par_no_vizinhos.second.end(),
                      [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                          return a.first < b.first;
                      });
        }
    }

    // Retorna true para indicar que tudo deu certo
    return true;
}