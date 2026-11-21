#include "acao_item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item{
    char nome[MAX_NOME_ITEM];
    int preco;
    int bonusForca;
};

Item* criaItem(char *nome, int preco, int bonusForca){
    Item *i = malloc(sizeof(struct Item));
    if(i == NULL){
        perror("ERRO ALOC ITEM\n");
        exit(1);
    }
    strcpy(i->nome, nome);
    i->preco = preco;
    i->bonusForca = bonusForca;
    return i;
}

Item* LeItem(){
    char nome[MAX_NOME_ITEM];
    int preco, bonusForca;
    scanf("%s ", nome);
    scanf("%d %d", &preco, &bonusForca);
    Item *i = criaItem(nome, preco, bonusForca);
    return i;
}

int ExecutaItem(void *dado, Jogador *j){
    Item *i = (Item*) dado;
    if(obtemOuroJogador(j) >= i->preco){
        adicionaOuroJogador(j, (i->preco)*-1);
        adicionaForcaJogador(j, i->bonusForca);
    }
    return 0;
}

void ImprimeItem(void *dado){
    Item *i = (Item*) dado;
    printf("ITEM %s (P:%d F:+%d)", i->nome, i->preco, i->bonusForca);
}

void DesalocaItem(void *dado){
    Item *i = (Item*) dado;
    free(i);
}