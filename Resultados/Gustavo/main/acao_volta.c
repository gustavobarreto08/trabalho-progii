#include "acao_volta.h"
#include "celula.h"
#include <stdlib.h>
#include <stdio.h>

struct Volta{
    int qtdCasas;
};

Volta* criaCasaVolta(int qtdCasas){
    Volta *v = malloc(sizeof(struct Volta));
    if(v == NULL){
        perror("ERRO ALOC VOLTA\n");
        exit(1);
    }
    v->qtdCasas = qtdCasas;
    return v;
}

Volta* LeCasaVolta(){
    int qtdCasas = 0;
    scanf("%d", &qtdCasas);
    Volta *v = criaCasaVolta(qtdCasas);
    return v;
}

int ExecutaVolta(void *dado, Jogador *j){
    Volta *v = (Volta*) dado;
    int posicaoAtualJog = obtemPosicaoJogador(j);
    if(posicaoAtualJog <= v->qtdCasas){
        return posicaoAtualJog*-1;
    }
    else{
        return (v->qtdCasas)*-1;
    }
}

void ImprimeVolta(void *dado){
    Volta *v = (Volta*) dado;
    printf("VOLTA %d", v->qtdCasas);
}

void DesalocaVolta(void *dado){
    Volta *v = (Volta*) dado;
    free(v);
}