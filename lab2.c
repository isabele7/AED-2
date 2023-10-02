#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um comprador
typedef struct {
    int senha;
    int valor_ofertado;
} Comprador;

int main() {
    char operacao;
    int valor;
    int senha_atual = 1;
    int max_comprador = 0;
    Comprador *fila_compradores = malloc(sizeof(Comprador) * 1000000);

    while (1) {
        scanf(" %c", &operacao);
        if (operacao == 'c') {
            scanf("%d", &valor);
            fila_compradores[max_comprador].senha = senha_atual++;
            fila_compradores[max_comprador].valor_ofertado = valor;
            max_comprador++;
        } else if (operacao == 'v') {
            int max_valor = 0;
            int idx_max_valor = -1;
            for (int i = 0; i < max_comprador; i++) {
                if (fila_compradores[i].valor_ofertado > max_valor) {
                    max_valor = fila_compradores[i].valor_ofertado;
                    idx_max_valor = i;
                }
            }
            if (idx_max_valor != -1) {
                printf("%d\n", fila_compradores[idx_max_valor].senha);
                // Remova o comprador da fila
                for (int i = idx_max_valor; i < max_comprador - 1; i++) {
                    fila_compradores[i] = fila_compradores[i + 1];
                }
                max_comprador--;
            } else {
                printf("0\n");
            }
        } else if (operacao == 'f') {
            break;
        }
    }

    free(fila_compradores);
    return 0;
}
