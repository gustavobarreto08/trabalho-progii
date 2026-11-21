#ifndef _OURO_H
#define _OURO_H

#include "jogador.h"

typedef struct Ouro Ouro;

Ouro* criaOuro(int qtdOuro);

Ouro* LeOuro();

int ExecutaOuro(void *dado, Jogador *j);

void ImprimeOuro(void *dado);

void DesalocaOuro(void *dado);

#endif