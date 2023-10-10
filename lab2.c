#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

typedef struct {
    int senha;
    int valor;
} Comprador;

Comprador fila[MAX];
int tamanho = 0;

void troca(Comprador *a, Comprador *b) {
    Comprador temp = *a;
    *a = *b;
    *b = temp;
}

void inserir(int senha, int valor) {
    Comprador novo;
    novo.senha = senha;
    novo.valor = valor;

    fila[tamanho] = novo;
    int atual = tamanho;

    while (atual > 0 && fila[atual].valor > fila[(atual - 1) / 2].valor) {
        troca(&fila[atual], &fila[(atual - 1) / 2]);
        atual = (atual - 1) / 2;
    }

    tamanho++;
}

int remover() {
    if (tamanho == 0) {
        return 0; 
    }
    int senha = fila[0].senha;
    fila[0] = fila[tamanho - 1];
    tamanho--;
    int atual = 0;
    while (1) {
        int e = 2 * atual + 1;
        int d = 2 * atual + 2;
        int maior = atual;
        if (e < tamanho && (fila[e].valor > fila[maior].valor || (fila[e].valor == fila[maior].valor && fila[e].senha < fila[maior].senha))) {
            maior = e;
        }
        if (d < tamanho && (fila[d].valor > fila[maior].valor || (fila[d].valor == fila[maior].valor && fila[d].senha < fila[maior].senha))) {
            maior = d;
        }
        if (maior != atual) {
            troca(&fila[atual], &fila[maior]);
            atual = maior;
        } else {
            break;
        }
    }
    return senha;
}

int main() {
    char operacao;
    int senha = 1;
    while (1) {
        scanf(" %c", &operacao);
        if (operacao == 'c') {
            int valor;
            scanf("%d", &valor);
            inserir(senha, valor);
            senha++;
        } else if (operacao == 'v') {
            int senha_vendida = remover();
            printf("%d\n", senha_vendida);
        } else if (operacao == 'f') {
            break;
        }
    }
    return 0;
}
