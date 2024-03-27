#include "modelagem.h"

using namespace std;

// Imprime todos os dados de input
void printData(int qtd_cidades, int qtd_rotas, int qtd_recursos, int qtd_pacotes, int ganho, vector<vector<int>> m_p, vector<vector<int>> m_r){
    cout << "Cidades: " <<  qtd_cidades  << " Rotas: " <<  qtd_rotas  << " Recursos: " <<  qtd_recursos << " Pacotes: " << qtd_pacotes << " Ganho: " << ganho << "\n\n";
    
    cout << "Vetor de Pacotes:\n";
    for(int i = 0; i < m_p.size(); i++){
        for(int j = 0; j < m_p[i].size(); j++){
            cout << m_p[i][j] << " ";
        } 
        cout << "\n";
    }
    cout << "\n\n";

    cout << "Matriz de Rotas:\n";
    for(int i = 0; i < m_r.size(); i++){
        for(int j = 0; j < m_r[i].size(); j++){
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

void funcao_objetivo(int ganho, vector<vector<int>> v, int qtd_pacotes){
    
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
        cout << "-" << m[i][2] << " <= rota_" << m[i][0] << m[i][1] << " <= " << m[i][2] << FIM;
    }
    cout << "\n\n";

    for(int i = 0; i < m.size(); i++){
        if(m[i][0] == 1){
            cout << "rota_" << m[i][0] << m[i][1] << " = ";
            for(int j = 0; j < m.size(); j++){
                if(m[j][0] == m[i][1]){
                    cout << "rota_" << m[j][0] << m[j][1];
                    if(j != m.size() - 1 && m[j+1][0] == m[i][1]){
                        cout << " + ";
                    }
                }
            }
            cout << FIM;
        }       
    }

    cout << "\n\n";

}

void recebido(int qtd_cidades, vector<vector<int>> m){
    cout << "recebido = ";
    for(int i = 0; i < m.size(); i++){
        if(m[i][1] == qtd_cidades){
            cout << "rota_" << m[i][0] << m[i][1];
            if(i != m.size() - 1){
                cout << " + ";
            }
        }

    }
    cout << FIM;
    cout << "\n";

    cout << "toneladas =";
    for(int i = 0; i < m.size(); i++){
        if(m[i][0] == 1){
            cout << " rota_" << m[i][0] << m[i][1];
            if(i != m.size() - 1 && m[i+1][0] == 1){
                cout << " +";
            }
        }
    }
    cout << FIM;
    cout << "\n\n";

}

// Imprime a quantidede de i-ésimo recurso no pacote j
void recursos_pacotes(int qtd_pacotes, vector<vector<int>> m, int qtd_recursos){
    for(int i = 0; i < qtd_pacotes ; i++){
        for(int j = 1; j <= qtd_recursos; j++){
            cout << "r_" << j << i << " = " << m[i][j] << FIM;
        }
    }
    cout << "\n\n";
}

void recursos_rotas(int qtd_rotas, vector<vector<int>> m, int qtd_recursos){
    for (int i = 0; i < m.size(); i++){
        for(int j = 1; j <= qtd_recursos; j++){
            cout << "s_" << j << m[i][0] << m[i][1] << " = " << m[i][j+2] << FIM;
        }
        cout << "\n";
    }
}

void modulo_rota(vector<vector<int>> m){
    for(int i = 0; i < m.size(); i++){
        cout << "mdl_rota_" << m[i][0] << m[i][1] << " >= ";
        cout << "-rota_" << m[i][0] << m[i][1] << FIM;        
    }
    cout << "\n";

    for(int i = 0; i < m.size(); i++){
        cout << "mdl_rota_" << m[i][0] << m[i][1] << " >= ";
        cout << "rota_" << m[i][0] << m[i][1] << FIM;        
    }
    cout << "\n";
    cout << "\n\n";
}

// com ajuda da variavel de existencia t_ij, na qual ij é o caminho de i até j, podemos indicar quantos recursos de cada tipo são necessários */
// recurso_necessario_1 = 1 mdl_rota_12 + 2 mdl_rota_13 + 1 mdl_rota_23 + 2 mdl_rota_24 + 3 mdl_rota_34;

void recurso_necessario(vector<vector<int>> m, int qtd_recursos){
    for(int i = 1; i <= qtd_recursos; i++){
        cout << "recurso_necessario_" << i << " = ";
        for(int j = 0; j < m.size(); j++){
            cout << m[j][i+2] << " mdl_rota_" << m[j][0] << m[j][1];
            if(j != m.size() - 1){
                cout << " + ";
            }
        }
        cout << FIM;
    }
    cout << "\n";
}


// recurso_comprado_1 = 4 p_1 + 5 p_2;
void recurso_comprado (vector<vector<int>> m, int qtd_recursos){
    for(int i = 1; i <= qtd_recursos; i++){
        cout << "recurso_comprado_" << i << " = ";
        for(int j = 0; j < m.size(); j++){
            cout << m[j][i] << " p_" << j+1;
            if(j != m.size() - 1){
                cout << " + ";
            }
        }
        cout << FIM;
    }
    cout << "\n";
}

void recurso_usado(int qtd_recursos){

    for(int i = 1; i <= qtd_recursos; i++){
        cout << "recurso_nescessario_" << i << " <= recurso_comprado_" << i << FIM;
    }
    cout << "\n";

}

void variaveis_int(vector<vector<int>> m){
    cout << "int ";
    for(int i = 0; i < m.size()-1; i++){
        cout << "rota_" << m[i][0] << m[i][1] << ", ";
    }
    cout << "rota_" << m[m.size()-1][0] << m[m.size()-1][1] << FIM;
    cout << "\n";
}
