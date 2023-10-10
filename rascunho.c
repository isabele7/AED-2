#include <stdio.h>
#include <stdlib.h>

int main() {
    int V, C, op1, op2, op3, votosValidos = 0, porcentagemVotos = 0;
    scanf("%d %d", &V, &C);

    if (C >= 1 && C <= 100) {
        int votosPrimeiroTurno[100] = {0};

        for (int i = 0; i < V; i++) {
            scanf("%d %d %d", &op1, &op2, &op3);
            votosPrimeiroTurno[op1]++;
            votosValidos++;
        }

        int maisVotado = votosPrimeiroTurno[1]; // Inicialize com o primeiro candidato
        for (int i = 2; i <= C; i++) {
            if (votosPrimeiroTurno[i] > maisVotado) {
                maisVotado = votosPrimeiroTurno[i];
            }
        }

        if (maisVotado >= 0.50 * votosValidos) {
            for (int i = 1; i <= C; i++) {
                if (votosPrimeiroTurno[i] == maisVotado) {
                    printf("%d %.2lf\n", i, (votosPrimeiroTurno[i] * 100.0) / votosValidos);
                    break;
                }
            }
        } else {
            int votosSegundoTurno[100] = {0};
            int segundoMaisVotado = 0;

            for (int i = 1; i <= V; i++) {
                if (op2 == maisVotado || op2 == segundoMaisVotado) {
                    votosSegundoTurno[op2]++;
                }
                if (op3 == maisVotado || op3 == segundoMaisVotado) {
                    votosSegundoTurno[op3]++;
                }
            }

            for (int i = 1; i <= C; i++) {
                if (votosSegundoTurno[i] > segundoMaisVotado) {
                    segundoMaisVotado = votosSegundoTurno[i];
                }
            }

            if (votosValidos > 0) {
                for (int i = 1; i <= C; i++) {
                    if (votosSegundoTurno[i] == segundoMaisVotado) {
                        printf("%d %.2lf\n", i, (votosSegundoTurno[i] * 100.0) / votosValidos);
                        break;
                    }
                }
            } else {
                printf("0\n");
            }
        }
    }

    return 0;
}
