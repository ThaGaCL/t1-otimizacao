#ifndef MODELAGEM_H
#define MODELAGEM_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#define FIM ";\n" 

using namespace std;

// Imprime todos os dados de input
void printData(int qtd_cidades, int qtd_rotas, int qtd_recursos, int qtd_pacotes, int ganho, vector<vector<int>> m_p, vector<vector<int>> m_r);

vector<int> le_vetor(int tam);

vector<vector<int>> le_matriz(int lin, int col);

void funcao_objetivo(int ganho, vector<vector<int>> v, int qtd_pacotes);

void rotas(vector<vector<int>> m);

void recebido(int qtd_cidades, vector<vector<int>> m);

void recursos_pacotes(int qtd_pacotes, vector<vector<int>> m, int qtd_recursos);

void recursos_rotas(int qtd_rotas, vector<vector<int>> m, int qtd_recursos);

void modulo_rota(vector<vector<int>> m);

void recurso_necessario(vector<vector<int>> m, int qtd_recursos);

void recursos_disponiveis(int qtd_recursos, vector<vector<int>> m, int qtd_pacotes, vector<vector<int>> v);


#endif