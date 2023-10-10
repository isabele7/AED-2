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
