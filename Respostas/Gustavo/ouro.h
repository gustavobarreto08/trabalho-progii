#ifndef _OURO_H
#define _OURO_H

#include "jogador.h"

typedef struct Ouro Ouro;

Ouro* criaOuro();

int ExecutaOuro(Ouro *o, Jogador *j);

void ImprimeOuro(Ouro *o);

void DesalocaOuro(Ouro *o);

#endif