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

        int maisVotadoPrimeiroTurno = votosPrimeiroTurno[1];
        int vencedorPrimeiroTurno = 1;

        for (int i = 2; i <= C; i++) {
            if (votosPrimeiroTurno[i] > maisVotadoPrimeiroTurno) {
                maisVotadoPrimeiroTurno = votosPrimeiroTurno[i];
                vencedorPrimeiroTurno = i;
            }
        }

        double porcentagemVotosPrimeiroTurno = (maisVotadoPrimeiroTurno * 100.0) / votosValidos;

        if (porcentagemVotosPrimeiroTurno >= 50.0) {
            printf("%d %.2lf\n", vencedorPrimeiroTurno, porcentagemVotosPrimeiroTurno);
        } else {
            int votosSegundoTurno[100] = {0};
            int maisVotadoSegundoTurno = 0;

            for (int i = 0; i < V; i++) {
                if (op2 == vencedorPrimeiroTurno || op2 == maisVotadoSegundoTurno) {
                    votosSegundoTurno[op2]++;
                }
                if (op3 == vencedorPrimeiroTurno || op3 == maisVotadoSegundoTurno) {
                    votosSegundoTurno[op3]++;
                }
            }

            for (int i = 1; i <= C; i++) {
                if (votosSegundoTurno[i] > maisVotadoSegundoTurno) {
                    maisVotadoSegundoTurno = votosSegundoTurno[i];
                }
            }

            if (votosValidos > 0) {
                for (int i = 1; i <= C; i++) {
                    if (votosSegundoTurno[i] == maisVotadoSegundoTurno) {
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

