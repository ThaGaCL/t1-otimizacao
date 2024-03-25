#include <stdio.h>
#include <stdlib.h>

void imprimirDados(int*  vetor, int tam, int** matriz, int linhas, int colunas) {
        printf("\nMatriz: \n");
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                printf("%d ", matriz[i][j]);
            }
        printf("\n");
        }

        printf("\nVetor de Pacotes: \n");
        for (int i = 0; i < tam; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");
}

int main(int argc, char *argv[]) {
    int qtd_cidades, qtd_rotas, qtd_recursos, qtd_pacotes, ganho;
    scanf("%d %d %d %d %d", &qtd_cidades, &qtd_rotas, &qtd_recursos, &qtd_pacotes, &ganho);

    int colunas = qtd_rotas + 1;
    int linhas = qtd_recursos + 2;
    int tam_vetor_pacotes = (qtd_recursos + 1) * qtd_pacotes;

    int** matriz_geral = malloc(sizeof(int*) * linhas);
    int* vetor_pacotes = malloc(sizeof(int) * tam_vetor_pacotes);
    
    for (int i = 0; i < colunas; i++) {
        matriz_geral[i] = malloc(sizeof(int) * colunas);
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz_geral[i][j]);
        }
    }

    for (int i = 0; i < tam_vetor_pacotes; i++) {
        scanf("%d", &vetor_pacotes[i]);
    }



    return 0;
}