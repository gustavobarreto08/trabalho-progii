#ifndef _ITEM_H
#define _ITEM_H

#define MAX_NOME_ITEM 21

#include "jogador.h"

typedef struct Item Item;

Item* criaItem(char *nome, int preco, int bonusForca);

Item* LeItem();

int ExecutaItem(void *dado, Jogador *j);

void ImprimeItem(void *dado);

void DesalocaItem(void *dado);

#endif