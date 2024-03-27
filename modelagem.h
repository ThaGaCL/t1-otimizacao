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

// Imprime a função objetivo
void funcao_objetivo(int ganho, vector<vector<int>> v, int qtd_pacotes);

// Imprime as restrições de rotas
void rotas(vector<vector<int>> m);

// Imprime as restricoes sobre os pacotes recebidos
void recebido(int qtd_cidades, vector<vector<int>> m);

// Imprime as restrições de relação entre recursos e pacotes
void recursos_pacotes(int qtd_pacotes, vector<vector<int>> m, int qtd_recursos);

// Imprime as restrições de relação entre recursos e rotas
void recursos_rotas(int qtd_rotas, vector<vector<int>> m, int qtd_recursos);

// Gera e imprime os modulos das rotas
void modulo_rota(vector<vector<int>> m);

// Imprime as restrições de recursos necessários
void recurso_necessario(vector<vector<int>> m, int qtd_recursos);

// Imprime as restrições de recursos disponíveis
void recurso_comprado(vector<vector<int>> m, int qtd_recursos);


void recurso_usado(int qtd_recursos);

void variaveis_int(vector<vector<int>> m);

#endif