#include "item.h"
#include <stdio.h>
#include <stdlib.h>

struct Item{
    char nome[21];
    int preco;
    int bonusForca;
};

Item* criaItem(){
    Item *i = malloc(sizeof(struct Item));
    if(i == NULL){
        perror("ERRO ALOC ITEM\n");
        exit(1);
    }
    return i;
}

int ExecutaItem(Item *i, Jogador *j){
    if(obtemOuroJogador(j) >= i->preco){
        adicionaOuroJogador(j, (i->preco)*-1);
        adicionaForcaJogador(j, i->bonusForca);
    }
    return 0;
}

void ImprimeItem(Item *i){
    printf("ITEM %s (P:%d F:+%d)", i->nome, i->preco, i->bonusForca);
}

void DesalocaItem(Item *i){
    free(i);
}