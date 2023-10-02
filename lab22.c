#include <stdio.h>
#include <stdlib.h>

#define MAX_OPERATIONS 1000000

// Estrutura para representar uma demanda por compra
typedef struct {
    int senha;
    int valor;
} Demanda;

// Função para comparar duas demandas com base no valor
int comparar_demanda(const void *a, const void *b) {
    return ((Demanda *)b)->valor - ((Demanda *)a)->valor;
}

int main() {
    char operacao;
    int valor;
    int num_operacoes = 0;
    Demanda fila[MAX_OPERATIONS];

    while (scanf(" %c", &operacao) != EOF) {
        if (operacao == 'c') {
            scanf("%d", &valor);
            fila[num_operacoes].senha = num_operacoes + 1;
            fila[num_operacoes].valor = valor;
            num_operacoes++;
            int atual = num_operacoes - 1;
            
            // Atualizar a fila de prioridade
            while (atual > 0) {
                int pai = (atual - 1) / 2;
                if (fila[atual].valor <= fila[pai].valor) break;
                // Trocar pai e filho
                Demanda temp = fila[atual];
                fila[atual] = fila[pai];
                fila[pai] = temp;
                atual = pai;
            }
        } else if (operacao == 'v') {
            if (num_operacoes > 0) {
                printf("%d\n", fila[0].senha);
                num_operacoes--;
                fila[0] = fila[num_operacoes];
                int atual = 0;
                
                // Atualizar a fila de prioridade
                while (1) {
                    int filho_esq = 2 * atual + 1;
                    int filho_dir = 2 * atual + 2;
                    int maior = atual;
                    
                    if (filho_esq < num_operacoes && fila[filho_esq].valor > fila[maior].valor) {
                        maior = filho_esq;
                    }
                    if (filho_dir < num_operacoes && fila[filho_dir].valor > fila[maior].valor) {
                        maior = filho_dir;
                    }
                    if (maior != atual) {
                        // Trocar pai e filho
                        Demanda temp = fila[atual];
                        fila[atual] = fila[maior];
                        fila[maior] = temp;
                        atual = maior;
                    } else {
                        break;
                    }
                }
            } else {
                printf("0\n");
            }
        } else if (operacao == 'f') {
            break;
        }
    }

    return 0;
}
