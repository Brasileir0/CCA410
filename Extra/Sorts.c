#include <stdio.h>

#define TAM 10

int BubbleSort(int v[]){
    for (int i = 0; i < TAM-1; i++) {
        for (int j = 0; j < TAM-1-i; j++) {
            if (v[j] > v[j+1]) {
                int aux = v[j];
                v[j] = v[j +1];
                v[j + 1] = aux;
            }
        }
    }
}

int InsertionSort(int v[]) {
    int chave;
    for (int j = 1; j < TAM-1; j++) {
        chave = v[j];
        int i = j - 1;
        while (i >= 0 && v[i] > chave) {
            v[i + 1] = v[i];
            i = i - 1;
            v[i + 1] = chave;
        }
    }
}

int SelectionSort(int v[]) {
    int min;
    for (int i = 0; i < TAM-2; i++) {
        min = i;
        for(int j = i + 1; j < TAM-1; j++) {
            if(v[j] < v[min]) {
                min = j;
            }
        }

        if (v[i] != v[min]) {
            int aux = v[i];
            v[i] = v[min];
            v[min] = aux;
        }
    }
}

int main()
{
	int V[TAM];

    V[0] = 8;
    V[1] = 2;
    V[2] = 1;
    V[3] = 6;
    V[4] = 7;
    V[5] = 0;
    V[6] = 3;
    V[7] = 5;
    V[8] = 4;
    V[9] = 9;

    printf("\n");
    printf("Vetor pré BubbleSort -> ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
	BubbleSort(V);
    printf("Vetor pós BubbleSort -> ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
    printf("\n");

    // Reset de Vetor
    V[0] = 8;
    V[1] = 2;
    V[2] = 1;
    V[3] = 6;
    V[4] = 7;
    V[5] = 0;
    V[6] = 3;
    V[7] = 5;
    V[8] = 4;
    V[9] = 9;

    printf("Vetor pré InsertionSort -> ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
	InsertionSort(V);
    printf("Vetor pós InsertionSort -> ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
    printf("\n");

    // Reset de Vetor
    V[0] = 8;
    V[1] = 2;
    V[2] = 1;
    V[3] = 6;
    V[4] = 7;
    V[5] = 0;
    V[6] = 3;
    V[7] = 5;
    V[8] = 4;
    V[9] = 9;

    printf("Vetor pré SelectionSort -> ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
	SelectionSort(V);
    printf("Vetor pós SelectionSort -> ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
    printf("\n");

	return 0;
}
