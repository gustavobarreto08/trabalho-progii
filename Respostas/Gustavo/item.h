#ifndef _ITEM_H
#define _ITEM_H

#include "jogador.h"

typedef struct Item Item;

Item* criaItem();

int ExecutaItem(Item *i, Jogador *j);

void ImprimeItem(Item *i);

void DesalocaItem(Item *i);

#endif