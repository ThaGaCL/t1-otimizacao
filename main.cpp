#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#define FIM ";\n;" 

using namespace std;

// Imprime todos os dados de input
void printData(int qtd_cidades, int qtd_rotas, int qtd_recursos, int qtd_pacotes, int ganho, vector<vector<int>> m_p, int lin_p, int col_p, vector<vector<int>> m_r, int lin, int col){
    cout << "Cidades: " <<  qtd_cidades  << " Rotas: " <<  qtd_rotas  << " Recursos: " <<  qtd_recursos << " Pacotes: " << qtd_pacotes << " Ganho: " << ganho << "\n\n";
    
    cout << "Vetor de Pacotes:\n";
    for(int i = 0; i < lin_p; i++){
        for(int j = 0; j < col_p; j++){
            cout << m_p[i][j] << " ";
        } 
        cout << "\n";
    }
    cout << "\n\n";

    cout << "Matriz de Rotas:\n";
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            cout << m_r[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

// Cria o vetor de pacotes
vector<int> le_vetor(int tam){
    vector<int> v(tam);
    
    for(int i = 0; i < tam; i++){
        cin >> v[i];
    }


    return v;
}

// Cria a matriz de rotas
vector<vector<int>> le_matriz(int lin, int col){
    vector<vector<int>> m(lin, vector<int>(col));
    
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            cin >> m[i][j];
        }
    }

    return m;

}

void funcao_objetivo(int ganho, vector<vector<int>> v, int lin_p, int col_p, int qtd_pacotes){
    
    cout << "max: ganho - custo;\n";
    cout << "ganho = " << ganho << " toneladas;\n";
    cout << "ganho >= 0;\n\n";

    cout << "custo =";
    for(int i = 1; i < qtd_pacotes; i++)
        cout << " custo_p" << i << " +";
    cout << " custo_p" << qtd_pacotes << FIM;
    cout << "custo >= 0;\n\n";

    for(int i = 1; i <= v.size(); i++){
        cout << "custo_p" << i << " = ";
        cout << v[i-1][0] << " p_" << i << FIM;
        cout << "p_" << i << " >= 0;\n";
    }
    cout << "\n\n";

} 

void rotas(vector<vector<int>> m){

    for(int i = 0; i < m.size(); i++){

    }

}

int main(){
    int custo;
    int qtd_cidades, qtd_rotas, qtd_recursos, qtd_pacotes, ganho;
    cin >> qtd_cidades >> qtd_rotas >> qtd_recursos >> qtd_pacotes >> ganho;

    vector<vector<int>> matriz_de_rotas;
    matriz_de_rotas = le_matriz(5, 6);

    vector<vector<int>> vetor_pacotes;
    vetor_pacotes = le_matriz(qtd_pacotes, qtd_recursos + 1);

    printData(qtd_cidades, qtd_rotas, qtd_recursos, qtd_pacotes, ganho, vetor_pacotes, qtd_pacotes, qtd_recursos + 1, matriz_de_rotas, 5, 6);
    funcao_objetivo(ganho, vetor_pacotes, qtd_pacotes, qtd_recursos + 1, qtd_pacotes);
    return 0;
}