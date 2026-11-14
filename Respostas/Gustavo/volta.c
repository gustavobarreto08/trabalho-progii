#include "volta.h"
#include "celula.h"
#include <stdlib.h>
#include <stdio.h>

struct Volta{
    int qtdCasas;
};

Volta* criaCasaVolta(){
    Volta *v = malloc(sizeof(struct Volta));
    if(v == NULL){
        perror("ERRO ALOC VOLTA\n");
        exit(1);
    }
    return v;
}

int ExecutaVolta(Volta *v, Jogador *j){
    int posicaoAtualJog = obtemPosicaoJogador(j);
    if(posicaoAtualJog <= v->qtdCasas){
        return 1;
    }
    else{
        return posicaoAtualJog - v->qtdCasas;
    }
}

void ImprimeVolta(Volta *v){
    printf("VOLTA %d", v->qtdCasas);
}

void DesalocaVolta(Volta *v){
    free(v);
}