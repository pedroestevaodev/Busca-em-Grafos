#include "leitura_grafos.h"
#include "definicoes_grafos.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

bool ler_grafo_g1(const string& nome_arquivo) {
    ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro: Nao foi possivel abrir o arquivo G1: " << nome_arquivo << endl;
        return false;
    }

    lista_adj_g1.clear();

    string linha;
    string no_u, no_v;
    while (getline(arquivo, linha)) {
        istringstream iss(linha);
        if (!getline(iss, no_u, ';') || !getline(iss, no_v, ';')) {
            cerr << "Aviso: Linha mal formatada em " << nome_arquivo << ": " << linha << endl;
            continue;
        }
        lista_adj_g1[no_u].push_back(no_v);
        lista_adj_g1[no_v].push_back(no_u);
    }
    for (auto& par_no_vizinhos : lista_adj_g1) {
        sort(par_no_vizinhos.second.begin(), par_no_vizinhos.second.end());
    }
    return true;
}

bool ler_grafo_g2(const string& nome_arquivo) {
    ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro: Nao foi possivel abrir o arquivo G2: " << nome_arquivo << endl;
        return false;
    }

    lista_adj_g2.clear();

    string linha;
    string no_u, no_v;
    while (getline(arquivo, linha)) {
        istringstream iss(linha);
        if (!getline(iss, no_u, ';') || !getline(iss, no_v, ';')) {
            cerr << "Aviso: Linha mal formatada em " << nome_arquivo << ": " << linha << endl;
            continue;
        }
        lista_adj_g2[no_u].push_back(no_v);
    }
    for (auto& par_no_vizinhos : lista_adj_g2) {
        sort(par_no_vizinhos.second.begin(), par_no_vizinhos.second.end());
    }
    return true;
}

bool ler_grafo_g3(const string& nome_arquivo) {
    ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro: Nao foi possivel abrir o arquivo G3: " << nome_arquivo << endl;
        return false;
    }

    lista_adj_g3.clear();

    string linha;
    string no_u_str, no_v_str, peso_str;
    int peso;

    while (getline(arquivo, linha)) {
        istringstream iss(linha);
        if (!getline(iss, no_u_str, ';') || !getline(iss, no_v_str, ';') || !getline(iss, peso_str)) {
            cerr << "Aviso: Linha mal formatada (esperado U;V;W) em " << nome_arquivo << ": " << linha << endl;
            continue;
        }

        try {
            peso = stoi(peso_str);
        } catch (const invalid_argument& e) {
            cerr << "Aviso: Peso invalido '" << peso_str << "' em linha: " << linha << " do arquivo " << nome_arquivo << endl;
            continue;
        } catch (const out_of_range& e) {
            cerr << "Aviso: Peso fora do alcance int '" << peso_str << "' em linha: " << linha << " do arquivo " << nome_arquivo << endl;
            continue;
        }

        lista_adj_g3[no_u_str].emplace_back(no_v_str, peso);
        lista_adj_g3[no_v_str].emplace_back(no_u_str, peso);
    }
    for (auto& par_no_vizinhos : lista_adj_g3) {
        sort(par_no_vizinhos.second.begin(), par_no_vizinhos.second.end());
    }
    return true;
}