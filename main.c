#include <stdio.h>

// Funcao auxiliar para imprimir o array na tela
void imprimirArray(float arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%.1f  ", arr[i]);
    }
    printf("\n");
}