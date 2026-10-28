#include <stdio.h>

// Funcao auxiliar para imprimir o array na tela
void imprimirArray(float arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%.1f  ", arr[i]);
    }
    printf("\n");
}
// --- BUBBLE SORT ---
void bubbleSort(float arr[], int tamanho) {
    float aux;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) { // Ordem crescente
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}
// --- QUICK SORT ---
int particionar(float arr[], int baixo, int alto) {
    float pivo = arr[alto];
    int i = (baixo - 1);
    float aux;
    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            aux = arr[i]; arr[i] = arr[j]; arr[j] = aux;
        }
    }
    aux = arr[i + 1]; arr[i + 1] = arr[alto]; arr[alto] = aux;
    return (i + 1);
}

void quickSort(float arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}
int main() {
    int tamanho = 10;
    float notasOriginais[10] = {7.5, 3.2, 9.8, 5.0, 8.4, 6.1, 10.0, 4.5, 7.0, 8.9};
    float notasBubble[10], notasQuick[10];
    
    for(int i = 0; i < tamanho; i++) {
        notasBubble[i] = notasOriginais[i];
        notasQuick[i] = notasOriginais[i];
    }

    printf("--- Sistema Escolar: Classificacao de Notas ---\n\n");
    printf("Notas ANTES da ordenacao:\n");
    imprimirArray(notasOriginais, tamanho);

    printf("\nNotas APOS ordenacao (BUBBLE SORT - Crescente):\n");
    bubbleSort(notasBubble, tamanho);
    imprimirArray(notasBubble, tamanho);

    printf("\nNotas APOS ordenacao (QUICK SORT - Crescente):\n");
    quickSort(notasQuick, 0, tamanho - 1);
    imprimirArray(notasQuick, tamanho);

    return 0;
}