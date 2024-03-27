#include "modelagem.h"

using namespace std;

int main(){
    int custo;
    int qtd_cidades, qtd_rotas, qtd_recursos, qtd_pacotes, ganho;
    cin >> qtd_cidades >> qtd_rotas >> qtd_recursos >> qtd_pacotes >> ganho;

    vector<vector<int>> matriz_de_rotas;
    matriz_de_rotas = le_matriz(qtd_rotas, qtd_recursos + 3);

    vector<vector<int>> vetor_pacotes;
    vetor_pacotes = le_matriz(qtd_pacotes, qtd_recursos + 1);

    // printData(qtd_cidades, qtd_rotas, qtd_recursos, qtd_pacotes, ganho, vetor_pacotes, matriz_de_rotas);
    
    funcao_objetivo(ganho, vetor_pacotes, qtd_pacotes);
    rotas(matriz_de_rotas);
    recebido(qtd_cidades, matriz_de_rotas);

    // recursos_pacotes(qtd_pacotes, vetor_pacotes, qtd_recursos);
    // recursos_rotas(qtd_rotas, matriz_de_rotas, qtd_recursos);

    modulo_rota(matriz_de_rotas);
    recurso_necessario(matriz_de_rotas, qtd_recursos);
    recurso_comprado(vetor_pacotes, qtd_recursos);
    recurso_usado(qtd_recursos);
    variaveis_int(matriz_de_rotas);

    return 0;
}