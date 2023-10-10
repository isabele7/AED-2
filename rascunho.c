#include <stdio.h>
#include <stdlib.h>

int main() {
    int V, C, op1, op2, op3, votosValidos = 0, porcentagemVotos;
    scanf("%d %d", &V, &C);
    if (C >= 1 && C < 100) {
        int votosPrimeiroTurno[100] = {0};
        for(int i = 0; i<V; i++){
            scanf("%d %d %d",op1,op2,op3);
            votosPrimeiroTurno[op1]++;
            votosValidos++;
        }
        int maisVotado = votosPrimeiroTurno[0];
        for(int i = 1; i<100; i++){
            if(votosPrimeiroTurno[i]>maisVotado){
                maisVotado = votosPrimeiroTurno[i+1];
            }
            for(int j = i; j>0; j--){
                if(votosPrimeiroTurno[j] == maisVotado){
                    maisVotado = votosPrimeiroTurno[j];
                    porcentagemVotos = (votosPrimeiroTurno[j] * 100.0) / votosValidos;
                }
            }
            int segundoMaisVotado = 
        }
        if(maisVotado >= 0.50*votosValidos){
            printf("%d %.2lf\n",maisVotado,porcentagemVotos);
        } else if(maisVotado < 0.50*votosValidos){
            int votosSegundoTurno[2] = {0};
            int segundoMaisVotado = votosSegundoTurno[0];
            for(int i = 0; i<V; i++){
                if(op2 == maisVotado || op2 == segundoMaisVotado){
                    votosPrimeiroTurno[op2]++;
                }
                if(op3 == maisVotado || op3 == segundoMaisVotado){
                    votosPrimeiroTurno[op3]++;
                }
            }
            porcentagemVotos = (votosSegundoTurno[j] * 100.0) / votosValidos-1;
        }
        printf(printf("%d %.2lf\n",vencedorSegundoTurno,porcentagemVotos))

        if(votosValidos == 0){
            printf("0\n");
        }
        return 0;
}
