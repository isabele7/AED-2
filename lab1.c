#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int buscaBinaria(int arr[], int tamanho, int alvo) {
    int l = 0;
    int r = tamanho - 1;
    
    while (l <= r) {
        int m = l + (r - l) / 2;
        
        if (arr[m] == alvo) {
            return 1; 
        } else if (arr[m] < alvo) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    
    return 0; 
}

int encontraPares(int arr[], int tamanho, int N) {
    qsort(arr, tamanho, sizeof(int), compare); 
    int count = 0;
    
    for (int i = 0; i < tamanho; i++) {
        int alvo = N - arr[i];
        if (buscaBinaria(arr, tamanho, alvo)) {
            count++;
        }
    }
    
    return count / 2; 
}

int main() {
    int S, N, s[10000];
    scanf("%d %d", &S, &N);
    for (int i = 0; i < S; i++) {
        scanf("%d", &s[i]);
    }
    int resultado = encontraPares(s, S, N);
    printf("%d\n", resultado);
    return 0;
}
