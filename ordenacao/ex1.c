#include <stdio.h>

void selecao(int v[], int n) {
    int i,j,aux,max;
    for (i = n - 1; i > 0; i--) {
        max = 0;
       // encontra elemento máximo
        for (j = 1; j <= i; j++) {
            if (v[j] > v[max]) {
                max = j;
            }
        }
        // troca da posição o elemento máximo pelo último elemento da parte não ordenada
        aux = v[max];
        v[max] = v[i];
        v[i] = aux;
    }
}

int main( ) {
    int n;
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    selecao(v, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
