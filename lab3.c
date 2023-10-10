#include <stdio.h>
#include <stdlib.h>

typedef struct Candidato {
    int chave;
    int votos;
    struct Candidato *esq, *dir, *pai;
} Candidato;

Candidato* novo(int x) {
    Candidato* temp = (Candidato*)malloc(sizeof(Candidato));
    temp->chave = x;
    temp->votos = 0; 
    temp->esq = temp-> pai = temp->dir = NULL;
    return temp;
}

Candidato* inserir(Candidato* candidato, int x){
    if (candidato == NULL)
        return novo(x);
    if (x < candidato->chave){
        Candidato *filhoE = inserir(filhoE->esq, x);
        candidato->esq  = filhoE;
        filhoE->pai = candidato;
    } else if (x > candidato->chave){
        Candidato *filhoD = inserir(filhoD->dir, x);
        candidato->dir = filhoD;
        filhoD->pai = candidato;
    }
    return candidato;
}

Candidato* primeiroTurno(Candidato* candidato, int votosValidos){
    struct Candidato* vencedor = candidato;
    while(candidato->dir!=NULL){
        vencedor = candidato->dir;
    }
    if(vencedor->votos > 0.50*votosValidos){
        while(vencedor->pai->votos == vencedor->votos){
            vencedor = vencedor->pai;
        }
    }
    return vencedor;
}

Candidato* segundoTurno(Candidato* candidato, Candidato* finalista1, Candidato* finalista2, int votosValidos){
    struct Candidato* vencedor = candidato;
    while(candidato->dir!=NULL){
        vencedor = candidato->dir;
    }
    if(vencedor->votos > 0.50*votosValidos){
        while(vencedor->pai->votos == vencedor->votos){
            vencedor = vencedor->pai;
        }
    }
    return vencedor;
}

int main(){
    int V, C, op1, op2, op3, votosValidos = 0;
    Candidato* raiz = NULL;
    scanf("%d %d",&V,&C);
    if(C>=1 && C<100){
        for(int i = 0; i < V; i++){
            scanf("%d %d %d",&op1,&op2,&op3);
            raiz = inserir(raiz, op1);
            votosValidos++;
        }
    }
    Candidato* vencedorPrimeiroTurno = primeiroTurno(raiz,votosValidos);
    float porcentagemVitoria = (vencedorPrimeiroTurno->votos)/votosValidos;
    if(vencedorPrimeiroTurno!=NULL){
        printf("%d %.2f",vencedorPrimeiroTurno->chave,porcentagemVitoria);
    }
    else{
        Candidato* finalista1 = vencedorPrimeiroTurno;
        Candidato* finalista2 = vencedorPrimeiroTurno->pai;
        for(int i = 0; i < V; i++){
        if(op2 == finalista1->chave){
            finalista1->votos++;
        }
        else if(op2 == finalista2->chave){
            finalista2->votos++;
        }
    }
    for(int i = 0; i < V; i++){
        if(op3 == finalista1->chave){
            finalista1->votos++;
        }
        else if(op3 == finalista2->chave){
            finalista2->votos++;
        }
    }
    for(int i = 0; i < V; i++){
        if(op1 != finalista1->chave && op1 != finalista2->chave && op2 != finalista1->chave 
        && op2 != finalista2->chave && op3 != finalista1->chave && op3!= finalista2->chave){
            votosValidos--;
        }
    }
        Candidato* vencedorSegundoTurno = segundoTurno(raiz,finalista1,finalista2,votosValidos);
        float porcentagemVitoria = (vencedorSegundoTurno->votos)/votosValidos;
        printf("%d %.2f",vencedorSegundoTurno->chave,porcentagemVitoria);
    }

    free(raiz);
    return 0;
}

#include <stdio.h>

int main() {
    int V, C;
    scanf("%d %d", &V, &C);

    int votos[C + 1] = {0}; // Inicializa o array de votos para cada candidato

    int primeiroTurno = 0;
    int segundoTurno = 0;

    // Processa os votos dos eleitores
    for (int i = 0; i < V; i++) {
        int voto1, voto2, voto3;
        scanf("%d %d %d", &voto1, &voto2, &voto3);

        // Verifica se o voto em primeira opção é válido
        if (voto1 >= 1 && voto1 <= C) {
            votos[voto1]++;
            // Verifica se alguém atingiu 50% dos votos válidos
            if (votos[voto1] * 2 > V) {
                primeiroTurno = voto1;
                break;
            }
        }
    }

    // Se não houver vencedor no primeiro turno
    if (primeiroTurno == 0) {
        int votosValidosPrimeiroTurno = 0;
        for (int i = 1; i <= C; i++) {
            // Verifica os candidatos que vão para o segundo turno
            if (votos[i] > votos[segundoTurno]) {
                segundoTurno = i;
            }
            votosValidosPrimeiroTurno += votos[i];
        }
        // Verifica se não houve votos válidos no primeiro turno
        if (votosValidosPrimeiroTurno == 0) {
            printf("0\n");
            return 0;
        }
    }

    // Calcula a porcentagem de votos do primeiro turno
    double porcentagemPrimeiroTurno = (double)votos[primeiroTurno] / V * 100;

    // Imprime os resultados
    printf("%d %.2lf\n", primeiroTurno, porcentagemPrimeiroTurno);

    // Se houver segundo turno, calcula a porcentagem de votos do segundo turno
    if (segundoTurno != 0) {
        double porcentagemSegundoTurno = (double)votos[segundoTurno] / V * 100;
        printf("%d %.2lf\n", segundoTurno, porcentagemSegundoTurno);
    }

    return 0;
}

